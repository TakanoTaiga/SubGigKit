# SubGigKit

Arduino library
簡単にIM920を使って通信するためのライブラリーです。
[このライブラリー](https://github.com/TakanoTaiga/SerialComsKit)に依存しています。ですがZipファイルにこのライブラリーは含まれています。

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
void Serialbegin()
```
この関数はシリアル通信の速度とTimeoutを決定しています。値は返しません。
```
(Int or Double or uInt)　SerialreadString(String,(Int or Double or uInt))
```
この関数は二つ目の引数の型が存在するか調べます。存在すれば二つ目の引数の型で返します。存在しない場合は０かNULLを返します。
```
String Serialprintln((Int or Double or uInt))
```
この関数はIM920で使用するデータに最適化します。String型を返します。
