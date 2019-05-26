# arm on QEMU

## on Ubuntu16.04
[QEMU でARM エミュレータ環境を作成する \- Qiita]( https://qiita.com/zonomasa/items/b33fba457503e166967a )

### setup
```
sudo apt-get install qemu
sudo apt-get install qemu-user-static
# 32bit
sudo apt-get install gcc-arm-linux-gnueabi
sudo apt-get install g++-arm-linux-gnueabi
sudo apt-get install g++-arm-linux-gnueabihf
# 64bit
sudo apt install g++-aarch64-linux-gnu
```

### how to compile
```
# 32bit
arm-linux-gnueabihf-g++ main.cpp
# 64bit
aarch64-linux-gnu-g++ main.cpp
```

### how to run
[export QEMU\_LD\_PREFIX=/usr/aarch64\-linux\-gnu/]( http://d.hatena.ne.jp/embedded/20140422/p1 )
> qemu-user-staticをインストールしたときにbinfmtの設定も行われているので、aarch64のELFオブジェクトを実行しようとすると自動的にqemu-aarch64-user-staticを経由して実行されるようになっています。

```
# 32bit
qemu-arm -L /usr/arm-linux-gnueabihf/ a.out
## or
export QEMU_LD_PREFIX=/usr/arm-linux-gnueabihf
./a.out

# 64bit
qemu-aarch64 -L /usr/aarch64-linux-gnu/ a.out
## or
export QEMU_LD_PREFIX=/usr/aarch64-linux-gnu/
./a.out
```

### neon
```
$ arm-linux-gnueabihf-g++ -mfpu=neon -std=c++11 neon_main.cpp -o neon_main
$ export QEMU_LD_PREFIX=/usr/arm-linux-gnueabihf
$ ./neon_main
8
10
12
14
16
18
20
22
-32
-32
-31
-31
-30
-30
-29
-29
32
32
33
33
34
34
35
35
```

<!-- ## on Max OS X -->
<!-- [【macOS】ARMのGCCコンパイル環境を構築する（brewからインストール） \| The modern stone age\.]( https://www.yokoweb.net/2018/05/16/macos-gcc-arm-brew-install/ ) -->
<!--  -->
<!-- ### how to install -->
<!-- ``` -->
<!-- $ brew tap PX4/homebrew-px4 -->
<!-- $ brew install gcc-arm-none-eabi -->
<!-- ``` -->
<!--  -->
<!-- ### how to confirm -->
<!-- ``` -->
<!-- $ arm-none-eabi-gcc --version -->
<!-- $ arm-none-eabi-g++ --version -->
<!-- -march=armv7-a -mfpu=neon -mfloat-abi=hard -mtune=cortex-a9 -->
<!-- ``` -->
----

#### 基本型
* [ARM Information Center ベクタのデータ型]( http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0472kj/chr1359125039392_00006.html )

### オーバーフロー
* [ARM NEONの使い方 加算編 \- おぺんcv]( http://atkg.hatenablog.com/entry/2016/10/09/173928 )

### 画像処理の例
* [Resize 8\-bit image by 2 with ARM NEON \- Stack Overflow]( https://stackoverflow.com/questions/17815959/resize-8-bit-image-by-2-with-arm-neon )
* [Resize 8\-bit image by 4 with ARM NEON \- Stack Overflow]( https://stackoverflow.com/questions/25234355/resize-8-bit-image-by-4-with-arm-neon )

## manual or dos
### 関数一覧のマニュアル with Supported Architectures
[ARM C Language Extensions\(NEON Intrinsics Reference\)]( http://infocenter.arm.com/help/topic/com.arm.doc.ihi0073a/IHI0073A_arm_neon_intrinsics_ref.pdf?resultof=%22%76%6d%6f%76%71%5f%6e%5f%66%33%32%22%20 )

### arm_neon.h ソースコード(gcc mirror)
[https://raw\.githubusercontent\.com/gcc\-mirror/gcc/master/gcc/config/aarch64/arm\_neon\.h]( https://raw.githubusercontent.com/gcc-mirror/gcc/master/gcc/config/aarch64/arm_neon.h )

