## About
西夏文字で表示する時計です。
時計としての実用性はありません。
TouchGFX の学習がてら作ったものです。

もともと西夏文字に魅力を感じていたところ、
TouchGFX を使えば多言語の UI が作れる…ということで
西夏文字＋TouchGFX で何かできないか考えた結果、これを作っていました。

多言語対応と組み合わせて他の文字（シンハラ文字とか）との
切り替えも検討したのですが、
西夏文字で統一したほうがおもしろかったので、そのようにしました。

## Software
UI は TouchGFX Designer で作成しました。
西夏文字以外は使っていません。

西夏文字は TTF フォントを TouchGFX Designer に読ませて利用しています。
ただ、西夏文字は Unicode の追加多言語面 (SMP;0x10000-)に登録されているのですが、
TouchGFX の方がこれに対応していなかったので、
私用領域（0xE000-）にマップされているフォントを使用する必要がありました。

操作方法は動画を参照してください。

## Hardware
ボードは [STM32F429I-DISCO](https://www.st.com/en/evaluation-tools/32f429idiscovery.html) をそのまま使いました。
時計としての性能は本質ではありませんので、これで十分でしょう。
ケースは 3D プリンタで作成しました。

## Tangut Language
西夏語は夏漢字典を引きながら入力しました。

ある程度意味は通ると思うのですが、
私は西夏語の専門家ではないので、
表記や文法には間違いを含むかもしれません。

なお時計の語は西夏語になかったので、計時機と訳しました。

## Another
西夏は元との戦いで敗れ、13世紀に降伏して滅亡しています。
征服された国家の行く末は悲惨であり、
西夏の文化はやがて忘れ去られ、西夏人という民族は失われ、
西夏語は 700 年後の 19 世紀になるまで”未解読言語”でした。
歴史は今後も繰り返すのでしょうか。

## Copyright
(c) 2024 Eleken 

## Reference
古今文字集成: http://www.ccamc.co
Tangut Character Lookup: https://tangut.info/
Tangut Script: https://www.babelstone.co.uk/Tangut/
English Language Index to Xia-Han Zidian: https://www.babelstone.co.uk/Tangut/XHZD_EnglishIndex.html
西夏文字フォント: https://www.babelstone.co.uk/Fonts/TangutScan.html
