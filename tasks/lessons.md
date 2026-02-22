# Lessons

## 2026-02-20: setup_42.sh 作成
- nvim設定は `~/.config/nvim/` にkickstart.nvimベースで構成済み
- GitHubリポ: `https://github.com/jsk-4970/kickstart-nvim.git` (private)
- 旧リポ `Rouboufy/kickstart.nvim` からmigrate済み
- 42 Macでは `/goinfre` にbrewを入れる必要がある（ホームのクォータ制限のため）
- Copilotは `github/copilot.vim` プラグインで設定済み、初回は `:Copilot auth` が必要
- Telescopeの依存: `ripgrep`, `fd`
- Node.jsはCopilotの依存

## CodeCultivation M01（2026-02-22）
- 技術的学び：継承チェーン（Plant→FloweringPlant→PrizeFlower）とメソッド種別（instance/classmethod/staticmethod）で「誰の責任か」を明確に分離する設計
- PMとしての学び：「この処理はインスタンスに紐づく？クラス全体？どちらでもない？」とエンジニアに聞けるようになった。仕様変更の影響範囲を継承ツリーで把握できる
- Visitasへの応用：ユーザー種別（Free/Premium/Enterprise）の権限設計は継承チェーンそのもの。統計モジュールはネストクラスで責任分離できる
