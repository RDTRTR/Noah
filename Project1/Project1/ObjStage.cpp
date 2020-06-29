//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjStage.h"
#include "main.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjStage::Init()
{
	m_scroll = 0.0f;

}


//�A�N�V����
void CObjStage::Action()
{
	//��l���̈ʒu���擾
	CObjNoah* noah = (CObjNoah*)Objs::GetObj(OBJ_NOAH);
	float hx = noah->GetX();
	float hy = noah->GetY();

	//����X�N���[�����C��
	if (hx < 80)
	{
		noah->SetX(50);				//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= noah->GetVX();		//��l�����{�������ׂ��l��m_scroll�ɉ�����
	}

	//�O���X�N���[�����C��
	if (hx > 750)
	{
		noah->SetX(300);				//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= noah->GetVX();		//��l�����{�������ׂ��l��m_scroll�ɉ�����
	}

	//�G�o�����C��
	//��l���̈ʒu�{500��G�o�����C���ɂ���
	float line = hx + (-m_scroll) + 500;

	////�G�o�����C����v�f�ԍ���
	//int ex = ((int)line) / 64;
	////�G�o�����C���̗������
	//for (int i = 0; i < 10; i++)
	//{
	//	//��̒�����4������
	//	if (m_map[i][ex] == 4)
	//	{
	//		CObjEnemy* obje = new CObjEnemy(ex * 64.0f, i * 64.0f);
	//		Objs::InsertObj(obje, OBJ_ENEMY, 10);
	//		//�G�o���̒l��0�ɂ���
	//		m_map[i][ex] = 0;
	//	}
	//}


}

//�h���[
void CObjStage::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�w�i�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1024.0f;
	src.m_bottom = 512.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom = WINDOW_SIZE_H;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	////�}�b�v�`�b�v�ɂ��block�ݒu
	//for (int i = 0; i < 10; i++)
	//{
	//	for (int j = 0; j < 100; j++)
	//	{
	//		if (m_map[i][j] > 0)
	//		{
	//			//�\���ʒu�̐ݒ�
	//			dst.m_top = i * 64.0f;
	//			dst.m_left = j * 64.0f + m_scroll;
	//			dst.m_right = dst.m_left + 64.0f;
	//			dst.m_bottom = dst.m_top + 64.0f;
	//			if (m_map[i][j] == 2)
	//			{
	//				//�X�^�[�g�u���b�N
	//				BlockDraw(320.0f + 64.0f, 0.0f, &dst, c);
	//			}
	//			else if (m_map[i][j] == 3)
	//			{
	//				//�S�[���u���b�N
	//				BlockDraw(320.0f + 64.0f, 64.0f, &dst, c);
	//			}
	//			else if (m_map[i][j] == 4)
	//			{
	//				;//�G�͈�l�̔ԍ��̂��߉������Ȃ�
	//			}
	//			else
	//			{
	//				BlockDraw(320.0f, 0.0f, &dst, c);
	//			}
	//		}
	//	}
	//}


}


/*
//BlockDrawMethod�֐�
//����1 float	x	:���\�[�X�؂���ʒuX
//����2 float	y	:���\�[�X�؂���ʒuY
//����3	RECT_F	dst	:�`�ʈʒu
//����4	float	c[]	:�J���[���
//�u���b�N��64�~64����`��p�B���\�[�X�؂���ʒu�̂�x�Ey�Őݒ�ł���
void CObjBlock::BlockDraw(float x, float y, RECT_F* dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = src.m_top + 64.0f;
	//�`��
	Draw::Draw(0, &src, dst, c, 0.0f);

}*/

/*
//BlockHit�֐�
//����1	float* x			:������s��object��X�ʒu
//����2	float* y			:������s��object��Y�ʒu
//����3	bool	scroll_on	:������s��object�̓X�N���[���̉e����^���邩�ǂ���(true:�^����@false:�^���Ȃ�)
//����4	bool	up			:�㉺���E����̏㕔���ɓ������Ă��邩��Ԃ�
//����5	bool	down		:�㉺���E����̉������ɓ������Ă��邩��Ԃ�
//����6	bool	left		:�㉺���E����̍������ɓ������Ă��邩��Ԃ�
//����7	bool	right		:�㉺���E����̉E�����ɓ������Ă��邩��Ԃ�
//����8	float*	vx			:���E���莞�̔����ɂ��ړ������E�͂̒l��ς��ĕԂ�
//����9	float*	vy			:�㉺���莞�ɂ�鎩�R�����^���̈ړ������E�͂̒l��ς��ĕԂ�
//����10	int*	bt			:���������莞�A����ȃu���b�N�̃^�C�v��Ԃ�
//������s��object�ƃu���b�N64�~64����ŁA�����蔻��Ə㉺���E������s��
//���̌��ʂ͈���4�`10�ɕԂ�

void CObjBlock::BlockHit(
	float* x, float* y, bool scroll_on,
	bool* up, bool* down, bool* left, bool* right,
	float* vx, float* vy, int* bt
)
{
	//��l���̏Փˏ�Ԋm�F�p�t���O�̏�����
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//����ł���block�̎�ނ̏�����
	*bt = 0;

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{

			if (m_map[i][j] > 0)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j * 64.0f;
				float by = i * 64.0f;

				//�X�N���[���̉e��
				float scroll = scroll_on ? m_scroll : 0;

				//��l���ƃu���b�N�̓����蔻��
				if ((*x + (-scroll) + 64.0f > bx) && (*x + (-scroll) < bx + 64.0f)
					&& (*y + 64.0f > by) && (*y < by + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx = *x + (-scroll) - bx;
					float rvy = *y - by;

					//���������߂�
					float len = sqrt(rvx * rvx + rvy * rvy);

					//�p�x�����߂�
					float r = atan2(rvy, rvx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//len��������̒������Z���ꍇ����ɓ���
					if (len < 88.0f)
					{

						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r>0) || r > 315)
						{
							//�E
							*right = true;//�I�u�W�F�N�g�̍��̕������Փ˂��Ă���
							*x = bx + 64.0f + (scroll);//�u���b�N�̈ʒu+�I�u�W�F�N�g�̕�
							*vx = -(*vx) * 0.1f;//-VX*�����W��

						}
						if (r > 45 && r < 135)
						{
							//��
							*down = true;//�I�u�W�F�N�g�̉��̕������Փ˂��Ă���
							*y = by - 64.0f;//�u���b�N�̈ʒu-�I�u�W�F�N�g�̕�
							//��ނ�n���̃X�^�[�g�ƃS�[���̂ݕύX
							if (m_map[i][j] >= 2)
								*bt = m_map[i][j];//�u���b�N�̗v�f(type)���I�u�W�F�N�g�ɓn��
							*vy = 0.0f;
						}
						if (r > 135 && r < 225)
						{
							//��
							*left = true;//�I�u�W�F�N�g�̉E�̕������Փ˂��Ă���
							*x = bx - 64.0f + (scroll);//�u���b�N�̈ʒu+�I�u�W�F�N�g�̕�
							*vx = -(*vx) * 0.1f;		//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							//��
							*up = true;//�I�u�W�F�N�g�̏�̕������Փ˂��Ă���
							*y = by + 64.0f;//�u���b�N�̈ʒu+�I�u�W�F�N�g�̕�
							if (*vy < 0)
							{
								*vy = 0.0f;
							}
						}
					}

				}

			}


		}
	}
}*/

/*
//���ϊ֐�
//����1,2	float	ax,ay	:A�x�N�g��
//����3,4	float	bx,by	:B�x�N�g��
//�߂�l	float	:�ˉe
//���e�@A�x�N�g����B�x�N�g���œ��ς��s���ˉe�����߂�

float CObjBlock::Dot(float ax, float ay, float bx, float by)
{
	float t = 0.0f;

	t = ax * bx + ay * by;

	return t;
}
*/

/*
//�O�ϊ֐�
//����1, 2	float	ax, ay	:A�x�N�g��
//����3, 4	float	bx, by : B�x�N�g��
//�߂�l	float : �ˉe
//���e�@A�x�N�g����B�x�N�g���ŊO�ς��s���ˉe�����߂�

float CObjBlock::Cross(float ax, float ay, float bx, float by)
{
	float t = 0.0f;

	t = ax * by - ay * bx;

	return t;
}

//���������߂�}�N��
#define SGN(x) 1-(x<=0)-(x<0)
*/

/*
//���Ɛ��̌�������֐�
//���� float	1,2		a1x,a1y				:���x�N�g��A�̎n�_
//���� float	3,4		a2x,a2y				:���x�N�g��A�̏I�_
//���� float	5,6		b1x,b1y				:�x�N�g��B�̎n�_
//���� float	7,8		b2x,b2y				:�x�N�g��B�̏I�_
//���� float	9,10	out_px,out_py		:��������x�N�g���̌�_�ʒu
//�߂�l bool		:true=��_�L��	false=��_����
//���e�F������A�EB�x�N�g���̌�_�������Aout_px��out_py�ɕԂ�

//���Ɛ��̌�������
bool CObjBlock::LineCrossPoint(
	float a1x, float a1y, float a2x, float a2y,
	float b1x, float b1y, float b2x, float b2y,
	float* out_px, float* out_py
)
{
	//�G���[�R�[�h
	*out_px = -99999.0f;	*out_px = -99999.0f;

	//A�x�N�g���쐬(a2��a1)
	float ax = a2x - a1x;	float ay = a2y - a1y;

	//B�x�N�g���쐬(b2��b1)
	float bx = b2x - b1x;	float by = b2y - b1y;

	//C�x�N�g���쐬(b1��a1)
	float cx = b1x - a1x;	float cy = b1y - a1y;

	//D�x�N�g���쐬(b2��a1)
	float dx = b2x - a1x;	float dy = b2y - a1y;

	//A�~C�̎ˉe��A�~B�̎ˉe�����߂�
	float t1 = Cross(ax, ay, cx, cy);
	float t2 = Cross(ax, ay, dx, dy);

	//���������������ɂȂ��Ă��邩�ǂ������`�F�b�N
	if (SGN(t1) == SGN(t2))
		return false;	//��_����

	//�ˉe���Βl��
	t1 = abs(t1);	t2 = abs(t2);

	//��_�����߂�
	float px = bx * (t1 / (t1 + t2)) + b1x;
	float py = by * (t1 / (t1 + t2)) + b1y;

	//AP�x�N�g��(p��a1)
	float apx = px - a1x;		float apy = py - a1y;

	//BP�x�N�g��(p��a2)
	float bpx = px - a2x;		float bpy = py - a2y;

	//A�EAP�̎ˉe��A�EBP�̎ˉe�����߂�
	float w1 = Dot(ax, ay, apx, apy);
	float w2 = Dot(ax, ay, bpx, bpy);

	//�����`�F�b�N
	if (SGN(w1) == SGN(w2))
		return false;	//��_���O

	//��_��Ԃ�
	*out_px = px;	*out_py = py;

	return true;

}
*/

/*
//��l���ƕǂ̌�������֐�
//����1,2 float	x,y					:��l���̈ʒu
//����3,4 float	vx,vy				:��l���̈ړ��x�N�g��
//����5,6 float*	out_px,out_y		:Block�Ƃ̌�_
//����7	float*	out					:�ʒu�����_�܂ł̋���
//��l���̈ʒu+�ړ��x�N�g���Ɗe�u���b�N�̕ӂŌ�_������s��
//�ł��߂���_�̈ʒu�Ƌ�����Ԃ�
bool CObjBlock::HeroBlockCrossPoint(
	float x, float y, float vx, float vy,
	float* out_px, float* out_py, float* out_len
)
{
	bool pb = false;			//��_�m�F�p
	float len = 99999.0f;		//��_�Ƃ̋���
	//�u���b�N�̕Ӄx�N�g��
	float edge[4][4] =
	{
		{ 0, 0,64, 0},//��
		{64, 0,64,64},//��
		{64,64, 0,64},//��
		{ 0,64, 0, 0},//��
	};

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 4)
			{
				//�u���b�N��4�ӂ����_��T��
				for (int k = 0; k < 4; k++)
				{
					//��_��T��
					float px, py;
					bool b;
					float l = 0.0f;
					b = LineCrossPoint(x, y, x + vx, y + vy,
						j * 64 + edge[k][0], i * 64 + edge[k][1], j * 64 + edge[k][2], i * 64 + edge[k][3],
						&px, &py);

					//��_�`�F�b�N
					if (b == true)
					{
						//��_�Ƃ̋��������߂�
						l = sqrt((px - x) * (px - x) + (py - y) * (py - y));

						//��������_�̒��ōł��������Z�����̂�T��
						if (len > 1)
						{
							len = l;
							*out_px = px;
							*out_py = py;
							pb = true;
						}
					}
				}
			}
		}
	}

	*out_len = len;
	return pb;
}
*/