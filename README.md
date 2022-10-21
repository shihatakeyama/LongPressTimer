# LongPressTimer
QPushButtonの長押しを検出してシグナルを通知します。

このプロジェクトは、QPushButtonを継承したり、格上げする事無く、シンプルなデザインに仕上げました。

■ポイント
 QPushButtonが押されたら
 ・LongPressTimer::longtouch()と長押し時に呼ばれるスロット関数をコネクトする。
 ・LongPressTimer::onReleased()とQPushButton::released()をコネクトして、タイマを起動する。
 
