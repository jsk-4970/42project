# Born2beRoot

> This project has been created as part of the 42 curriculum by jyamada.

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

### OS Selection

本プロジェクトでは **Debian** を選択。

| OS | パッケージ形式 | 特徴 |
|---|---|---|
| **Debian** | `.deb` / `apt` | コミュニティ駆動。安定性重視。Debian Policyが厳格 |
| **Rocky Linux** | `.rpm` / `dnf` | RHEL互換。企業向けサポートを重視した設計 |

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
| **PermitRootLogin no** | root直接ログインを禁止 |

### UFW (Uncomplicated Firewall)

Stateful Inspectionにより、パケットの中身だけでなく通信の状態を管理。許可された通信の戻りパケットを自動的に通す。

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

## Usage

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

## Resources

- [Debian Documentation](https://www.debian.org/doc/)
- [AppArmor Wiki](https://gitlab.com/apparmor/apparmor/-/wikis/home)
- [Sudoers Manual](https://www.sudo.ws/man/sudoers.man.html)

---

## AI Usage Disclosure

| 項目 | 内容 |
|---|---|
| 利用タスク | `monitoring.sh` における `awk` を使ったシステム情報取得コマンドの構文調査 |
| 利用箇所 | メモリ使用率およびディスク使用率の計算ロジック |
| 使用理由 | 正確なシステムリソースのパース方法を効率的に特定するため |
