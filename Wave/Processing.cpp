// Processing.cpp: implementation of the CProcessing class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "Processing.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProcessing::CProcessing()
{

}

CProcessing::~CProcessing()
{

}

//������������ �������: Data-�������� ������, NumOfPoints-����� �������
void CProcessing::FFTReorder(complex<float> Data[],unsigned int NumOfPoints)
{
	for (int j=0;j<NumOfPoints;j++)
	{          //���������� ������ �������� �� ���������
		int inverse=0;
		int l=1;
		int t=NumOfPoints/2;
		for(int d=1;d<NumOfPoints;d*=2)
		{
			inverse=inverse+l*(j&t)/t;                      
			l=l*2;
			t=t/2;
		}

		if(j<inverse)                       //�������� ����, ��� �� ���������� �������� ������������
		{
			complex<float> temp;           //������������ ���������
			temp=Data[j];
			Data[j]=Data[inverse];
			Data[inverse]=temp;
		}
	}
}
//������� �������������� �����:Data-�������� ������(� ���� �� � ��������� ����� ������),NumOfPoints-����� �������
//������������ �����
//������� ���������� ������� ������������ ������� ��������-������ ReOrdeer
//Dir-����������� ��������������:1 - ������, -1 - ��������(����� �������� ���� ��������� ���������� ������ ��������-������ ReOrder)
//�����!!!!! ���� �� ������ �����-�������������� ������������������, � ����� ������ �������� ��������������, ��
//������������������, ���������� ����� ��������� �������������� ����� �������� �� ������ ������� N.
void CProcessing::FFT(complex<float> Data[],unsigned int NumOfPoints,int Dir)
{
	int Step, HalfStep;
	int b;
	double pi=3.1415926535897932384626433832;
	complex <float> wtemp ; 
	Step = 1;
	while (Step < NumOfPoints) 
	{
		HalfStep = Step;
		Step *= 2;
		complex <float> w(1,0);                         //�� ������ cos(x), ������ cos(x)-1 � ���� -2sin^2(x/2);
		complex <float> Root(-2*sin(Dir*pi/(2*HalfStep))*sin(Dir*pi/(2*HalfStep)),sin(Dir*pi/HalfStep));
		int L,R; 
		for (b = 0; b < HalfStep; b++)
		{
			for (L=b; L<NumOfPoints; L+=Step)
			{
				complex <float>TRight,TLeft;    //�������     
				R=L+HalfStep;
				TLeft=Data[L];TRight=Data[R];
				TRight = TRight * w;
				Data[L] = TLeft + TRight;
				Data[R] = TLeft - TRight;
			}
			                                         
			wtemp=w;      //������� � ���������� ��������������� ���������
			w=w*Root;
			w=w+wtemp;
		}
	}
	
}



void CProcessing::Gilbert(complex<float> Data[],unsigned int NumOfPoints)
{
	complex <float> doubler(2,0);
	complex <float> zero(0,0);
	int a;
	float re,im;
	for(a=0; a<NumOfPoints; a++)
	{
		if (a<NumOfPoints/2)
		{
			
			Data[a]=Data[a]*doubler;
			
		}
		else
		{
			
			Data[a]=Data[a]*zero;
		}
	}
}
