# Born2beRoot

> This project has been created as part of the 42 curriculum by jyamada.

## Description

Born2beRootは、仮想化（Virtualization）の基礎を学び、自分自身の最初のサーバーを構築するプロジェクトです。

VirtualBoxを使用して、グラフィカルインターフェースを持たない最小構成のオペレーティングシステム（Debian）をインストールし、厳格なセキュリティルールやシステム管理設定を実装します。

このプロジェクトの目的は、以下を通じてシステム管理の基本概念を理解することにあります：

- LVMによるパーティショニング
- sudoの設定
- SSHサービス
- UFW/firewalldによるファイアウォール
- 強力なパスワードポリシー
- システム状態を監視するスクリプトの作成

---

### 1. Operating System: Debian vs Rocky Linux

本プロジェクトでは **Debian** を選択しました。

| OS | メリット | デメリット |
|---|---|---|
| Debian | 安定性が高く、パッケージ管理(APT)が直感的。初心者向けのリソースが豊富。 | 最新機能の導入がRockyに比べて遅い場合がある。 |
| Rocky Linux | RHEL互換であり、エンタープライズ環境に近い。SELinuxが標準。 | 設定がDebianより複雑で、初心者には難易度が高い。 |

### 2. Security & Tools Comparison

#### AppArmor vs SELinux

| ツール | 説明 |
|---|---|
| AppArmor (Debian採用) | パスベースのアクセス制御。設定が比較的容易で人間が読みやすい。 |
| SELinux (Rocky採用) | ラベルベースのアクセス制御。より細粒度な制御が可能だが、学習曲線が急。 |

#### UFW vs firewalld

| ツール | 説明 |
|---|---|
| UFW (Debian採用) | "Uncomplicated Firewall"の略。シンプルなコマンドで直感的にポート開放が可能。 |
| firewalld (Rocky採用) | ゾーンベースの管理が可能で、動的なルール変更に強い。 |

#### VirtualBox vs UTM

| ツール | 説明 |
|---|---|
| VirtualBox | 広く普及しているクロスプラットフォームの仮想化ソフト。Intel MacやWindowsで安定。 |
| UTM | Apple Silicon (M1/M2/M3) Macに最適化された軽量な仮想化ソフト。 |

### 3. Design Choices

- **Partitioning**: LVM（Logical Volume Manager）を使用し、将来の拡張性を確保。
- **Security**: SSHポートをデフォルトの22から4242に変更し、rootログインを禁止。
- **Sudo**: すべての入出力をログに記録（`/var/log/sudo/`）し、TTYモードを強制。

---

## Instructions

### Prerequisites

- VirtualBox または UTM がインストールされていること。
- VMのディスクシグネチャ（`.vdi` または `.qcow2`）が `signature.txt` と一致していること。

### How to Run

1. VirtualBoxを起動し、対象のVMを選択して「起動」をクリック。
2. ログイン画面が表示されたら、作成したユーザー名またはrootでログイン。
3. SSH経由で接続する場合（ホストマシンのターミナルから）:

```bash
ssh <user>@localhost -p 4242
```

---

## Reviewer's Manual (Evaluation Guide)

レビュー時に必要となる操作コマンドとチェック項目をまとめています。

### 1. サービスの確認

| 項目 | コマンド |
|---|---|
| AppArmorの状態確認 | `sudo aa-status` |
| UFWの状態確認 | `sudo ufw status` |
| SSHポートの確認 | `ss -tunlp` (4242ポートが開いているか確認) |

### 2. ユーザー・グループ管理 (レビュー中に指示される操作)

| 操作 | コマンド |
|---|---|
| 新規ユーザー作成 | `sudo adduser <new_username>` |
| 新規グループ作成 | `sudo addgroup <group_name>` |
| ユーザーをグループに追加 | `sudo adduser <username> <group_name>` |
| パスワードポリシーの確認 | `/etc/login.defs` および `/etc/pam.d/common-password` を確認 |

### 3. ホスト名の変更

| 操作 | コマンド |
|---|---|
| 現在のホスト名確認 | `hostnamectl` |
| 一時的な変更 | `sudo hostnamectl set-hostname <new_hostname>` |

> 変更後は再起動またはシェルを再起動して反映を確認してください。

### 4. Monitoring Script

`monitoring.sh` は cron によって10分おきに実行されます。

| 項目 | パス/コマンド |
|---|---|
| スクリプトの場所 | `/usr/local/bin/monitoring.sh` |
| cronの設定確認 | `sudo crontab -u root -e` |
| 即時実行 | `sudo /usr/local/bin/monitoring.sh` |

---

## Resources

- [Debian Documentation](https://www.debian.org/doc/)
- [AppArmor Wiki](https://gitlab.com/apparmor/apparmor/-/wikis/home)
- [Sudoers Manual](https://www.sudo.ws/man/sudoers.man.html)

---

## AI Usage Disclosure

本プロジェクトにおけるAI（ChatGPT/Gemini等）の利用状況は以下の通りです：

| 項目 | 内容 |
|---|---|
| 利用タスク | `monitoring.sh` における `awk` を使ったシステム情報取得コマンドの構文調査 |
| 利用箇所 | メモリ使用率およびディスク使用率の計算ロジック |
| 使用理由 | 正確なシステムリソースのパース方法を効率的に特定するため |
