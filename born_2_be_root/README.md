# Born2beRoot

*This project has been created as part of the 42 curriculum by jyamada.*

## Description

Born2beRootは、仮想化（Virtualization）の基礎を学び、自分自身の最初のサーバーを構築するプロジェクトです。

VirtualBoxを使用して、グラフィカルインターフェースを持たない最小構成のオペレーティングシステム（Debian）をインストールし、厳格なセキュリティルールやシステム管理設定を実装します。

**学習目標:**
- LVMによるパーティショニング
- sudoの設定
- SSHサービス
- UFWによるファイアウォール
- 強力なパスワードポリシー
- システム監視スクリプトの作成

---

## Technical Background

### Virtualization

| 用語 | 説明 |
|---|---|
| **Hypervisor** | 物理ハードウェアと仮想マシンの間でリソースを仲介するソフトウェア層 |
| **Type-2 (ホスト型)** | VirtualBoxがこれに該当。既存のOS上で動作するため導入が容易 |
| **Type-1 (ベアメタル型)** | ESXiやXen。ハードウェア上で直接動作し、オーバーヘッドが少ない |
| **Kernel** | OSの中核。ハードウェアを管理し、アプリケーションに抽象化されたリソースを提供 |

### OS Selection: Debian vs Rocky Linux

本プロジェクトでは **Debian** を選択。

| OS | Pros | Cons |
|---|---|---|
| **Debian** | 安定性が高い、APTが直感的、初心者向けリソースが豊富 | 最新機能の導入が遅い場合がある |
| **Rocky Linux** | RHEL互換、エンタープライズ環境に近い、SELinux標準 | 設定が複雑、初心者には難易度が高い |

### AppArmor vs SELinux

| ツール | 採用OS | 特徴 |
|---|---|---|
| **AppArmor** | Debian | パスベースのアクセス制御。設定が比較的容易で可読性が高い |
| **SELinux** | Rocky | ラベルベースのアクセス制御。細粒度な制御が可能だが学習曲線が急 |

### UFW vs firewalld

| ツール | 採用OS | 特徴 |
|---|---|---|
| **UFW** | Debian | "Uncomplicated Firewall"。シンプルなコマンドで直感的に操作可能 |
| **firewalld** | Rocky | ゾーンベースの管理。動的なルール変更に強い |

### VirtualBox vs UTM

| ツール | 特徴 |
|---|---|
| **VirtualBox** | クロスプラットフォーム。Intel Mac/Windowsで安定 |
| **UTM** | Apple Silicon (M1/M2/M3) Macに最適化された軽量な仮想化ソフト |

---

## LVM & LUKS

### LVM (Logical Volume Manager)

```
┌─────────────────────────────────────────────┐
│              LV (Logical Volume)            │  ← OSから見える仮想パーティション
├─────────────────────────────────────────────┤
│              VG (Volume Group)              │  ← PVを束ねたストレージプール
├──────────────────┬──────────────────────────┤
│  PV (Physical    │  PV (Physical Volume)    │  ← 実際のディスクパーティション
│  Volume)         │                          │
└──────────────────┴──────────────────────────┘
```

| 層 | 説明 |
|---|---|
| **PV** | 実際のディスクパーティション（`/dev/sda3`など） |
| **VG** | PVを束ねた仮想的なストレージプール |
| **LV** | VGから切り出された仮想パーティション。オンラインで拡張可能 |

### LUKS (Linux Unified Key Setup)

| 項目 | 説明 |
|---|---|
| **仕組み** | ディスク上のデータをセクタ単位で暗号化 |
| **dm-crypt** | カーネル内のサブシステム。起動時に暗号化キーを解除し、透過的なアクセスを提供 |

---

## Security Configuration

### Sudo

| 設定 | 目的 |
|---|---|
| **requiretty** | TTYセッションなしでのsudo実行を遮断 |
| **secure_path** | 信頼できるパスのみを使用させ、悪意あるバイナリの実行を防止 |
| **logfile** | すべての入出力を `/var/log/sudo/` に記録 |

### PAM (Pluggable Authentication Modules)

Linuxにおける認証の共通基盤。パスワードポリシー（`libpam-pwquality`）はPAMの一環。

| 用語 | 説明 |
|---|---|
| **Entropy** | パスワードの予測不可能性 |
| **Dictionary Attack** | 既知の単語リストを用いた総当たり攻撃 |

### Password Policy

#### 強度設定 (Quality Control)

設定ファイル: `/etc/pam.d/common-password`

| 設定 | 説明 |
|---|---|
| `minlen=10` | パスワードは最低10文字以上 |
| `ucredit=-1` | 最低1文字は大文字を含める |
| `lcredit=-1` | 最低1文字は小文字を含める |
| `dcredit=-1` | 最低1文字は数字を含める |
| `maxrepeat=3` | 同じ文字を3回以上連続させない |
| `reject_username` | パスワードにユーザー名を含めない |
| `difok=7` | 古いパスワードと少なくとも7文字は異なる |
| `enforce_for_root` | これらのルールをrootにも適用 |

#### 期限設定 (Expiration Policy)

設定ファイル: `/etc/login.defs`

| 設定 | 説明 |
|---|---|
| `PASS_MAX_DAYS 30` | パスワードの有効期限は最大30日 |
| `PASS_MIN_DAYS 2` | 変更後、次に変更できるまで最低2日 |
| `PASS_WARN_AGE 7` | 期限切れ7日前から警告を表示 |

#### 確認方法

```bash
# 特定ユーザーのパスワード期限を確認
sudo chage -l <username>
```

#### 既存ユーザーへの適用

`/etc/login.defs` の設定は**新規作成ユーザーにのみ**自動適用される。既存ユーザーには個別に設定が必要。

```bash
sudo chage -M 30 -m 2 -W 7 <username>
```

| オプション | 説明 |
|---|---|
| `-M 30` | 最大有効期限を30日に設定 |
| `-m 2` | 最小変更間隔を2日に設定 |
| `-W 7` | 警告を7日前から表示 |

### AppArmor

| 制御方式 | 説明 |
|---|---|
| **MAC** | Mandatory Access Control。管理者が決めたルールに従い、rootでも制限を受ける |
| **DAC** | Discretionary Access Control。通常の権限（`chmod`など） |

AppArmorはパス名ベースでプロセスをサンドボックス化し、脆弱性があってもシステム全体への被害拡大を防止する。

### Configuration Files

| カテゴリ | パス | 確認内容 |
|---|---|---|
| Sudo設定 | `/etc/sudoers.d/sudo_config` | パスワード試行回数、カスタムエラー等 |
| Sudoログ | `/var/log/sudo/` | 実行履歴（sudo.logなど）の有無 |
| パスワード強度 | `/etc/pam.d/common-password` | `minlen=10` や `ucredit=-1` などの設定 |
| パスワード期限 | `/etc/login.defs` | `PASS_MAX_DAYS 30` などの設定 |
| SSH設定 | `/etc/ssh/sshd_config` | ポート番号（4242）の設定 |
| ホスト名 | `/etc/hosts` | ホスト名が正しく設定されているか |
| 自作スクリプト | `/usr/local/bin/monitoring.sh` | 10分おきに表示される情報のコード |

---

## Network Configuration

### SSH

| 設定 | 効果 |
|---|---|
| **Port 4242** | デフォルトの22番を避け、自動スキャン攻撃を回避 |
| **Protocol 2** | 現在の標準。脆弱なProtocol 1は使用しない |
| **PermitRootLogin no** | root直接ログインを禁止。管理者権限への直接アクセスを制限 |

#### 確認方法

```bash
# サービスの動作確認
sudo systemctl status ssh

# 設定ファイルの確認
sudo nano /etc/ssh/sshd_config
# → Port 4242, PermitRootLogin no を確認
```

#### 外部からの接続

```bash
# ホストマシンから接続
ssh <username>@<ip_address> -p 4242

# VMのIPアドレスを確認
hostname -I
```

### UFW (Uncomplicated Firewall)

Stateful Inspectionにより、パケットの中身だけでなく通信の状態を管理。許可された通信の戻りパケットを自動的に通す。

#### 確認方法

```bash
# インストール確認
dpkg -l | grep ufw

# ステータス表示（番号付き）
sudo ufw status numbered
```

#### ルールの追加と削除

```bash
# ポートを許可
sudo ufw allow 8080

# ステータスで追加を確認
sudo ufw status numbered

# ルールを削除（番号で指定）
sudo ufw delete <rule_number>
```

---

## Monitoring Script

### 概要

`monitoring.sh` は cron によって定期実行され、`wall` コマンドで全ユーザーにシステム情報を表示する。

### 確認方法

```bash
# スクリプトの存在確認
ls /usr/local/bin/monitoring.sh

# cronの設定確認
sudo crontab -u root -l

# 手動実行
sudo /usr/local/bin/monitoring.sh
```

### 実行頻度の変更

```bash
sudo crontab -u root -e
```

| 設定 | 実行頻度 |
|---|---|
| `*/10 * * * *` | 10分ごと（デフォルト） |
| `*/1 * * * *` | 1分ごと |

変更後、指定した間隔でシステム情報が `wall` コマンドで全端末に表示される。

---

## User & Group Management

### グループ所属の確認

ユーザーが `sudo` および `user42` グループに属しているか確認する。

```bash
getent group sudo
getent group user42
```

> `getent` はシステムデータベース（グループ情報等）からエントリを取得するコマンド。
> `groups [username]` でも確認可能。

### ユーザーの作成

```bash
sudo adduser <new_username>
```

パスワード設定時、設定したパスワードポリシー（10文字以上、大文字・小文字・数字を含む等）が適用される。

### グループの作成と割り当て

```bash
# グループ作成
sudo groupadd <group_name>

# ユーザーをグループに追加
sudo usermod -aG <group_name> <username>
```

| オプション | 説明 |
|---|---|
| `-a` | append。既存のグループから削除せずに追加 |
| `-G` | 追加するグループを指定 |

> `-a` を付けないと、そのユーザーが現在所属している他のグループ（sudoなど）から外れてしまう。

### 確認

```bash
# グループ所属確認
getent group <group_name>

# パスワード期限の確認
sudo chage -l <username>
```

`chage -l` の出力例：
- パスワードの最大有効期限: 30日
- 変更までの最小日数: 2日
- 警告: 7日前から表示

### ホスト名の変更

```bash
# 現在のホスト名を確認
hostnamectl

# ホスト名を変更
sudo hostnamectl set-hostname <new_hostname>

# /etc/hosts を編集して古いホスト名を新しいものに書き換え
sudo nano /etc/hosts

# 再起動して反映
sudo reboot
```

再起動後、ログインプロンプトのホスト名が変わっていることを確認。

---

## Glossary

| 用語 | 説明 |
|---|---|
| **Aptitude** | `apt`のハイレベルなフロントエンド。複雑な依存関係の解決に優れる |
| **Cron** | 時系列ベースのジョブスケジューラ |
| **Wall** | "Write All"。全ユーザーにメッセージを表示 |
| **Snapshot** | 特定時点のファイルシステムやVMの状態を保存したもの |
| **FHS** | Filesystem Hierarchy Standard。Linuxのディレクトリ構造の配置基準 |

---

## Command Reference

### System

```bash
uname -a          # カーネルバージョン、アーキテクチャ、OS名
hostnamectl       # ホスト名、OSの詳細、仮想化の種類
uptime            # 稼働時間、ログインユーザー数、ロードアベレージ
```

### Storage

```bash
lsblk -f          # パーティション、LVM、ファイルシステム
pvs / vgs / lvs   # LVM各レイヤーの詳細
df -Th            # マウントされているディスクの容量
```

### User Management

```bash
id [user]                # UID, GID, 所属グループ
getent group [group]     # グループの所属メンバー
sudo adduser <username>  # ユーザー作成
sudo addgroup <group>    # グループ作成
```

### Network & Security

```bash
ss -tunlp                # リスニングポート、プロトコル、PID
ufw status numbered      # ファイアウォールルール
aa-status                # AppArmorの状態
journalctl -u ssh        # SSHサーバーのログ
```

### Hostname

```bash
hostnamectl                                    # 確認
sudo hostnamectl set-hostname <new_hostname>   # 変更
```

---

## Instructions

### Prerequisites

- VirtualBox または UTM
- VMのディスクシグネチャが `signature.txt` と一致していること

### Run

```bash
ssh <user>@localhost -p 4242
```

### Monitoring Script

| 項目 | 値 |
|---|---|
| Location | `/usr/local/bin/monitoring.sh` |
| Cron | `sudo crontab -u root -e` |
| Manual run | `sudo /usr/local/bin/monitoring.sh` |

---

## Bonus Part Guide

このセクションでは、Born2beRootプロジェクトにおけるボーナスパートの構成内容と、その検証方法について解説します。

### 📋 ボーナスパートの内容

ボーナスパートでは、以下の3つの項目をすべて完璧に実装する必要があります。

| 項目 | 説明 |
|---|---|
| **高度なパーティショニング** | LVMを利用し、暗号化されたボリューム内に少なくとも2つの追加パーティションを作成する |
| **WordPressのセットアップ** | Lighttpd, MariaDB, PHP を使用して、実際に動作するWordPressサイトを構築する |
| **追加サービスの導入** | 必須要件にはない独自のサービスを導入する（例: Fail2ban, FTP など） |

### 1. 💽 高度なパーティショニング (LVM)

必須課題の構成に加え、さらに論理ボリューム（LV）を分割して管理します。

#### 検証コマンド

```bash
# 現在のパーティション構造を確認
lsblk
```

#### 構成例

- `/` (Root)
- `/home`
- `/var/log` (追加)
- `/tmp` (追加)

など、複数のマウントポイントがLVM配下にあることを示します。

### 2. 🌐 WordPress サービス構成

軽量な Lighttpd サーバー上でWordPressを動作させます。

#### スタック構成

| コンポーネント | 使用ソフトウェア |
|---|---|
| Web Server | lighttpd |
| Database | MariaDB |
| Language | PHP (php-fpm / php-cgi) |

#### 検証方法

ホストマシンのブラウザから以下のURLにアクセスできることを確認します。
（ポートフォワーディングの設定が必要です。例：ポート 80 または指定したポート）

```
http://<VM_IP_OR_LOCALHOST>:<PORT>/
```

#### サービス状態の確認コマンド

```bash
sudo systemctl status lighttpd
sudo systemctl status mariadb
sudo systemctl status php*-fpm
```

### 3. 🛡️ 追加サービス (Fail2ban)

セキュリティ強化のため、Fail2ban を導入して不正なSSHアクセスを自動的にブロックします。

#### Fail2ban の役割

ログファイルを監視し、設定した回数以上のログイン失敗があったIPアドレスを、一定時間ファイアウォール（UFW）で拒否します。

#### 検証コマンド

```bash
# サービスの状態確認
sudo systemctl status fail2ban

# 現在のステータスとブロックされているIPの確認
sudo fail2ban-client status sshd
```

### ⚙️ 評価時のチェックリスト

| チェック項目 | 確認内容 |
|---|---|
| LVM | `lsblk` コマンドで、複数のパーティションが動的に管理されているか？ |
| Web Server | lighttpd が正常に動作し、WordPressの初期設定画面（または記事）が表示されるか？ |
| Database | WordPressがMariaDBに正常に接続できているか？ |
| Bonus Service | 導入したサービス（Fail2ban等）の目的を説明し、動作していることを証明できるか？ |
| UFW | WordPress用（HTTP）および追加サービス用のポートが適切に開放されているか？ |

### 💡 注意事項

| 項目 | 説明 |
|---|---|
| **完全性** | 必須課題（Mandatory Part）が1つでも不合格の場合、ボーナスパートは採点されません |
| **説明** | 評価者に対して、「なぜそのパーティション構成にしたのか」「Fail2banがどのように動作するのか」を論理的に説明できるように準備してください |

---

## Resources

- [Debian Documentation](https://www.debian.org/doc/)
- [AppArmor Wiki](https://gitlab.com/apparmor/apparmor/-/wikis/home)
- [Sudoers Manual](https://www.sudo.ws/man/sudoers.man.html)

---

## AI Usage Disclosure

| 項目 | 内容 |
|---|---|
| 利用タスク | 技術的背景の広範なリサーチ、README作成 |
| 利用箇所 | 本ドキュメント全体 |
| 使用理由 | 技術情報の整理と文書構成の効率化 |
