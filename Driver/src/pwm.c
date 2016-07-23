
#include "PWM.h"

/***************************************************************
** ��������: PWMInit
** ��������: PWM��ʼ������
** �䡡��:   
** �䡡��:   
** ȫ�ֱ���: 
** ������:   ����ʵ����
** ��  ����  Http://miaowlabs.taobao.com
** �ա���:   2014��08��01��
***************************************************************/
void PWMInit()
{	

	P_SW2|=0x80;    //ʹ�ܷ���XSFR

	PWMCFG = 0x00;                  //����PWM�������ʼ��ƽΪ�͵�ƽ
	PWMCKS = 0x00;                  //ѡ��PWM��ʱ��ΪFosc/(0+1)=20M
	PWMIF=0x00; 
	PWMFDCR=0x00; 

	PWMC = 1001;                   //��λ������ʱ�� ����PWM����(���ֵΪ32767)	PWMƵ��=20M/1000=20k
	
	PWM2T1 = 1000;                 //����PWM3��1�η�ת��PWM����
    PWM2T2 = 1001;    			 	//����PWM3��2�η�ת��PWM����
									//ռ�ձ�Ϊ(PWM3T2-PWM3T1)/PWMC
									//��ʼPWM3ռ�ձ�Ϊ100%
	PWM3T1 = 1000;                 //����PWM3��1�η�ת��PWM����
    PWM3T2 = 1001;    			 	//����PWM3��2�η�ת��PWM����
									//ռ�ձ�Ϊ(PWM3T2-PWM3T1)/PWMC
									//��ʼPWM3ռ�ձ�Ϊ100%

	PWM4T1 = 1000;                 //����PWM4��1�η�ת��PWM����
    PWM4T2 = 1001;    				//����PWM4��2�η�ת��PWM����
									//ռ�ձ�Ϊ(PWM4T2-PWM4T1)/PWMC
									//��ʼPWM4ռ�ձ�Ϊ100%
	PWM5T1 = 1000;                 //����PWM3��1�η�ת��PWM����
    PWM5T2 = 1001;    			 	//����PWM3��2�η�ת��PWM����
									//ռ�ձ�Ϊ(PWM3T2-PWM3T1)/PWMC
									//��ʼPWM3ռ�ձ�Ϊ100%
	PWM2CR=0x00; 
	PWM3CR=0x00;
	PWM4CR=0x00; 
	PWM5CR=0x00; 

    PWMCR = 0x8F;                   //ʹ��PWM�ź�
   
	//P_SW2 &= ~0x80;
 }
/*
void PCAInit()
{
	CMOD = 0x04;//ѡ��ʱ��0�����������Ϊ����Դ
	AUXR1 |= 0x20;	//�л�����
	PCA_PWM0 = 0x00 ;//8λPWM,���ж�
	PCA_PWM1= 0x00;
	CL = 0;         //���ɵ���������16λPCA��ʱ����ֵ,��ʼ��Ϊ0
	CH = 0;
	CCAP0H = CCAP0L = 0x00;	//���ڿ���ռ�ձȣ�ռ�ձ�=(255-CCAPnL)/255*100%
  	CCAP1H = CCAP1L = 0x00; //��ʼ��ռ�ձ�Ϊ50%
	CR = 1;	//PCA���������п�ʼ										 
	 //PWM��Ƶ��=PCAʱ������ԴƵ��/256
}
*/
//�����������4��ֵȡֵ��ΧΪ0-1000 1000���ͣ��0ת����ߣ��������ݲ��ܳ���ȡֵ��Χ������������
void PWM(unsigned int PWMa,unsigned int PWMb,unsigned int PWMc,unsigned int PWMd)
{  
	PWM2T1 = PWMa;	
	PWM3T1 = PWMb;	
	PWM4T1 = PWMc;
	PWM5T1 = PWMd;
}
