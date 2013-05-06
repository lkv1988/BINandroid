BINandroid v0.1
==========

### 一个纯粹的Android bin开发环境，初始化于Android4.1.2版本，代码来源CyanogenMod10。

        庞大的Android系统使得一些bin开发者不堪重负，不但开发的时候要进行整套Android代码的同步下载，
    而且在编译调试的时候还要付出大量的时间用于代码编译前的收集等待。可能一个小功能、一个小demo
    仅仅需要几分钟就可以搞定，但是下载编译却要花去N倍的时间。
        所以我建立了这样一个项目，这个项目仅仅不到600MB，只有一个git来管理，多数bin开发能够用到的库
    已经集成，起码现在完整编译recovery是没有问题的，优点就是快！缺点当然就是除了开发bin啥也干不了。

    重点提示：本环境基于Android4.1.2，编译出来的bin在同版本系统上方能运行，其他版本运行的话进程会被直接kill掉。

### 使用说明

        用BINandroid开发调试只需要把你的device放进来即可，当然也可以通过./build/tool/device/mkvendor.sh
    生成。如果放进去的device code在breakfast的时候存在问题，那么请注意错误提示，一般会是cm.mk中引用了并
    不存在的文件，当然这些文件是被我精简掉了的。
    
        1.开发recovery
        开发recovery的话，直接make recoveryimage或make recoveryzip就可以。区别是：recoveryimage生成
    recovery.img；而recoveryzip会生成一个update.zip刷机包，可以通过现有recovery进行刷机测试（不会覆盖
    当前recovery）。
        2.开发BIN
        开发BIN的话，我本人是习惯把项目放到external下边，然后LOCAL_MODULE_TAGS := optional，再在调试所用
    device中包含这个LOCAL_MODULE的名字。

### 欢迎各位使用，提出宝贵的意见建议，及Pull request！  :)
