using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace mhy_가위바위보
{
    public partial class mhy_가위바위보 : Form
    {
        public mhy_가위바위보()
        {
            InitializeComponent();
        }

        bool result_view; //결과 보기 플래그
        int User_count = 0, Com_count = 0, Draw_count = 0;
        int User_S = 0, User_R = 0, User_P = 0;
        int Com_S = 0, Com_R = 0, Com_P = 0;

        private void btn_View_Result_Click(object sender, EventArgs e)
        {
            Timer_View_Result.Start();
        }

        private void Timer_View_Result_Tick(object sender, EventArgs e)
        {
            int size = 20;
            if (!result_view)
            {
                if (Width >= MaximumSize.Width)
                {
                    Width = MaximumSize.Width;
                    result_view = true;
                    btn_View_Result.Text = "결과 접기◀";
                    Timer_View_Result.Stop();
                }
                else
                {
                    Width += size;
                }
            }
            else
            {
                if (Width <= MinimumSize.Width)
                {
                    Width = MinimumSize.Width;
                    result_view = false;
                    btn_View_Result.Text = "결과 보기▶";
                    Timer_View_Result.Stop();
                }
                else
                {
                    Width -= size;
                }
            }

            //결과 출력하기
            lb_Me_Score.Text = string.Format("내가 이긴 횟수 : {0}번", User_count);
            lb_Com_Score.Text = string.Format("컴이 이긴 횟수 : {0}번", Com_count);
            lb_Draw_Score.Text = string.Format("비긴 횟수 : {0}번", Draw_count);
            lb_Total_Count.Text = string.Format("총 {0}번의 게임을 진행하였습니다.", Com_count+User_count+Draw_count);
            lb_Me_S.Text = string.Format("가위 수 : {0}", User_S);
            lb_Me_R.Text = string.Format("바위 수 : {0}", User_R);
            lb_Me_P.Text = string.Format("보 수 : {0}", User_P);
            lb_Com_S.Text = string.Format("가위 수 : {0}", User_S);
            lb_Com_R.Text = string.Format("바위 수 : {0}", User_R);
            lb_Com_P.Text = string.Format("보 수 : {0}", User_P);
        }



        private void gawei_Click(object sender, EventArgs e)
        {
            int my_num = 1;
            User_S++;
            pictureBox2.ImageLocation = "Images/gawei.jpg";
            Random rand = new Random(); //컴퓨터의 선택
            int com = rand.Next(1, 4);

            if (com == 1) { pictureBox1.ImageLocation = "Images/gawei.jpg"; Com_S++; }
            else if (com == 2) { pictureBox1.ImageLocation = "Images/bawei.jpg"; Com_R++; }
            else { pictureBox1.ImageLocation = "Images/bo.jpg"; Com_P++; }
            result.Text = 가위바위보.가위바위보.WhoIsWinner(com, my_num);

            if (result.Text == "내가 이김") User_count++;
            else if (result.Text == "내가 짐") Com_count++;
            else Draw_count++;
        }

        private void bawei_Click(object sender, EventArgs e)
        {
            int my_num = 2;
            User_R++;
            pictureBox2.ImageLocation = "Images/bawei.jpg";
            Random rand = new Random(); //컴퓨터의 선택
            int com = rand.Next(1, 4);
            if (com == 1) { pictureBox1.ImageLocation = "Images/gawei.jpg"; Com_S++; }
            else if (com == 2) { pictureBox1.ImageLocation = "Images/bawei.jpg"; Com_R++; }
            else { pictureBox1.ImageLocation = "Images/bo.jpg"; Com_P++; }
            result.Text = 가위바위보.가위바위보.WhoIsWinner(com, my_num);

            if (result.Text == "내가 이김") User_count++;
            else if (result.Text == "내가 짐") Com_count++;
            else Draw_count++;
        }

        private void bo_Click(object sender, EventArgs e)
        {
            int my_num = 3;
            User_P++;
            pictureBox2.ImageLocation = "Images/bo.jpg";
            Random rand = new Random(); //컴퓨터의 선택
            int com = rand.Next(1, 4);
            if (com == 1) { pictureBox1.ImageLocation = "Images/gawei.jpg"; Com_S++; }
            else if (com == 2) { pictureBox1.ImageLocation = "Images/bawei.jpg"; Com_R++; }
            else { pictureBox1.ImageLocation = "Images/bo.jpg"; Com_P++; }
            result.Text = 가위바위보.가위바위보.WhoIsWinner(com, my_num);

            if (result.Text == "내가 이김") User_count++;
            else if (result.Text == "내가 짐") Com_count++;
            else Draw_count++;
        }
    }
}
