#include <QtGui/QApplication>
#include "ffpmmainw.h"
#include "test.h"

//#include "pro_test.h"   //M6G2c项目-最基础运行环境测试


int main(int argc, char *argv[])
{
    // QTextCodec::setCodecForCStrings(QTextCodec::codecForName("文泉驿微米黑"));
      QApplication a(argc, argv);
      FFPMMainW w;
     //pro_test w;         //M6G2c项目-最基础运行环境测试
     w.show();
    return a.exec();
}


/*
程序编写记录:
0: 自2018年4月起所有的程序修改日志均放在 main.cpp中
1: 2018-4-8- 完成时间设置 - form_set_pra.cpp

//2018年8月21日
        条目                                          进度
1: 电流超限判断有bug                               其它文件完成，本项目带修改-待测试                 ffpmmainw.cpp  786
2：电流采集要求乘以电路变比，数据库                    待完成
同时增加电流变比值，电压电流报警值采用
百分比(数据以1-150表示1%-150%),
额定电压值230V ,电流值5A*rate.
电压默认欠压值： 78 %
       过呀值： 110 %
电流默认欠流值： 1%  (默认不启用)
       过流值:  110%
设计时需考虑电流是否要小数位(显示宽度问题)

3: 密码123456 登录bug.



4：报警不保持（电压电流故障，恢复后，报警自动解除）    修改待议

5： 2018-8-24日，在公司编写程序bug记录，
    5.1：程序编译后，到arm板上运行，直接报seagement error, 采用printf 打印程序进度，找到错误在，my_test.cpp 文件中，72-74行
    5.2：接上一个V3的模块，监测发现，模块只有在复位后第一次能和arm板正常通讯，（arm 循环发送1-20地址的查询指令），
         若用串口调试助手单点和模块通信，模块又是好的。。。
    5.3 在公司完成前期测试，将模块的电压，电流数据以浮点数的格式运算，并按格式，控制小数输出。

6：



*/
