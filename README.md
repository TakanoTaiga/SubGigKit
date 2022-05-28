# SubGigKit Alpha version

Arduino Framework 
簡単にIM920を使って通信するためのライブラリーです。

## Overview

```
#include <SubGigKitUno.hpp>

void setup() {
  SubGigKit::Serialbegin();
}

void loop() {
  if(Serial.available()){
    Serial.println(SubGigKit::SerialreadString(":F11234",1));
    Serial.println(SubGigKit::Serialprintln(12345));
  }
}

//prints 1234
         TXDAF112345E0
         
```

## Reference

### include
Use Arduino Uno
```
SubGigKitUno.hpp
```
Use Arduino Mega and Due
```
Coming soom.
```
### namespace
```
SubGigKit
```
### functions
```
void Serialbegin(int SerialChannel = 0)
```
この関数はシリアル通信の速度とTimeoutを決定しています。値は返しません。
```
(Int or Double or uInt)　SerialreadString(String,(Int or Double or uInt) , uInt address)
```
この関数は二つ目の引数の型が存在するか調べます。存在すれば二つ目の引数の型で返します。存在しない場合は０かNULLを返します。addressはオプションです。アドレスを指定するとアドレスが送信と受信が一致している時のみに通信が成立します。
```
String Serialprintln((Int or Double or uInt) , uInt address)
```
この関数はIM920で使用するデータに最適化します。String型を返します。addressはオプションです。アドレスを指定するとアドレスが送信と受信が一致している時のみに通信が成立します。アドレスは単一のプログラムの中で複数使用できます。
