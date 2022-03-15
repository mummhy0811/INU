namespace mhy_가위바위보
{
    partial class mhy_가위바위보
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(mhy_가위바위보));
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.result = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.gawei = new System.Windows.Forms.Button();
            this.bawei = new System.Windows.Forms.Button();
            this.bo = new System.Windows.Forms.Button();
            this.btn_View_Result = new System.Windows.Forms.Button();
            this.Timer_View_Result = new System.Windows.Forms.Timer(this.components);
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.lb_Me_Score = new System.Windows.Forms.Label();
            this.lb_Com_Score = new System.Windows.Forms.Label();
            this.lb_Draw_Score = new System.Windows.Forms.Label();
            this.lb_Total_Count = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.lb_Me_S = new System.Windows.Forms.Label();
            this.lb_Com_S = new System.Windows.Forms.Label();
            this.lb_Me_R = new System.Windows.Forms.Label();
            this.lb_Com_R = new System.Windows.Forms.Label();
            this.lb_Me_P = new System.Windows.Forms.Label();
            this.lb_Com_P = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(25, 46);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(22, 15);
            this.label1.TabIndex = 0;
            this.label1.Text = "컴";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(24, 155);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(22, 15);
            this.label2.TabIndex = 1;
            this.label2.Text = "나";
            // 
            // result
            // 
            this.result.AutoSize = true;
            this.result.Location = new System.Drawing.Point(261, 155);
            this.result.Name = "result";
            this.result.Size = new System.Drawing.Size(37, 15);
            this.result.TabIndex = 2;
            this.result.Text = "결과";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(123, 12);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(100, 97);
            this.pictureBox1.TabIndex = 3;
            this.pictureBox1.TabStop = false;
            // 
            // pictureBox2
            // 
            this.pictureBox2.Location = new System.Drawing.Point(123, 126);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(100, 97);
            this.pictureBox2.TabIndex = 4;
            this.pictureBox2.TabStop = false;
            // 
            // gawei
            // 
            this.gawei.Font = new System.Drawing.Font("굴림", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.gawei.ForeColor = System.Drawing.Color.Red;
            this.gawei.Image = ((System.Drawing.Image)(resources.GetObject("gawei.Image")));
            this.gawei.Location = new System.Drawing.Point(20, 244);
            this.gawei.Name = "gawei";
            this.gawei.Size = new System.Drawing.Size(98, 97);
            this.gawei.TabIndex = 5;
            this.gawei.Text = "1";
            this.gawei.UseVisualStyleBackColor = true;
            this.gawei.Click += new System.EventHandler(this.gawei_Click);
            // 
            // bawei
            // 
            this.bawei.Font = new System.Drawing.Font("굴림", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.bawei.ForeColor = System.Drawing.Color.Red;
            this.bawei.Image = ((System.Drawing.Image)(resources.GetObject("bawei.Image")));
            this.bawei.Location = new System.Drawing.Point(124, 244);
            this.bawei.Name = "bawei";
            this.bawei.Size = new System.Drawing.Size(98, 97);
            this.bawei.TabIndex = 6;
            this.bawei.Text = "2";
            this.bawei.UseVisualStyleBackColor = true;
            this.bawei.Click += new System.EventHandler(this.bawei_Click);
            // 
            // bo
            // 
            this.bo.Font = new System.Drawing.Font("굴림", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.bo.ForeColor = System.Drawing.Color.Red;
            this.bo.Image = ((System.Drawing.Image)(resources.GetObject("bo.Image")));
            this.bo.Location = new System.Drawing.Point(225, 244);
            this.bo.Name = "bo";
            this.bo.Size = new System.Drawing.Size(98, 97);
            this.bo.TabIndex = 7;
            this.bo.Text = "3";
            this.bo.UseVisualStyleBackColor = true;
            this.bo.Click += new System.EventHandler(this.bo_Click);
            // 
            // btn_View_Result
            // 
            this.btn_View_Result.Location = new System.Drawing.Point(233, 189);
            this.btn_View_Result.Name = "btn_View_Result";
            this.btn_View_Result.Size = new System.Drawing.Size(90, 34);
            this.btn_View_Result.TabIndex = 8;
            this.btn_View_Result.Text = "결과보기▶";
            this.btn_View_Result.UseVisualStyleBackColor = true;
            this.btn_View_Result.Click += new System.EventHandler(this.btn_View_Result_Click);
            // 
            // Timer_View_Result
            // 
            this.Timer_View_Result.Tick += new System.EventHandler(this.Timer_View_Result_Tick);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.lb_Com_P);
            this.groupBox1.Controls.Add(this.lb_Me_P);
            this.groupBox1.Controls.Add(this.lb_Com_R);
            this.groupBox1.Controls.Add(this.lb_Me_R);
            this.groupBox1.Controls.Add(this.lb_Com_S);
            this.groupBox1.Controls.Add(this.lb_Me_S);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.lb_Total_Count);
            this.groupBox1.Controls.Add(this.lb_Draw_Score);
            this.groupBox1.Controls.Add(this.lb_Com_Score);
            this.groupBox1.Controls.Add(this.lb_Me_Score);
            this.groupBox1.Location = new System.Drawing.Point(351, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(269, 329);
            this.groupBox1.TabIndex = 9;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "게임결과";
            // 
            // lb_Me_Score
            // 
            this.lb_Me_Score.AutoSize = true;
            this.lb_Me_Score.Location = new System.Drawing.Point(22, 36);
            this.lb_Me_Score.Name = "lb_Me_Score";
            this.lb_Me_Score.Size = new System.Drawing.Size(107, 15);
            this.lb_Me_Score.TabIndex = 0;
            this.lb_Me_Score.Text = "내가 이긴 횟수";
            // 
            // lb_Com_Score
            // 
            this.lb_Com_Score.AutoSize = true;
            this.lb_Com_Score.Location = new System.Drawing.Point(22, 60);
            this.lb_Com_Score.Name = "lb_Com_Score";
            this.lb_Com_Score.Size = new System.Drawing.Size(107, 15);
            this.lb_Com_Score.TabIndex = 1;
            this.lb_Com_Score.Text = "컴이 이긴 횟수";
            // 
            // lb_Draw_Score
            // 
            this.lb_Draw_Score.AutoSize = true;
            this.lb_Draw_Score.Location = new System.Drawing.Point(22, 84);
            this.lb_Draw_Score.Name = "lb_Draw_Score";
            this.lb_Draw_Score.Size = new System.Drawing.Size(72, 15);
            this.lb_Draw_Score.TabIndex = 2;
            this.lb_Draw_Score.Text = "비긴 횟수";
            // 
            // lb_Total_Count
            // 
            this.lb_Total_Count.AutoSize = true;
            this.lb_Total_Count.Location = new System.Drawing.Point(21, 109);
            this.lb_Total_Count.Name = "lb_Total_Count";
            this.lb_Total_Count.Size = new System.Drawing.Size(92, 15);
            this.lb_Total_Count.TabIndex = 3;
            this.lb_Total_Count.Text = "총 게임 횟수";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(6, 156);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(239, 15);
            this.label3.TabIndex = 4;
            this.label3.Text = "-----------------------------";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(31, 187);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(177, 15);
            this.label4.TabIndex = 5;
            this.label4.Text = "나의                      컴의";
            // 
            // lb_Me_S
            // 
            this.lb_Me_S.AutoSize = true;
            this.lb_Me_S.Location = new System.Drawing.Point(22, 222);
            this.lb_Me_S.Name = "lb_Me_S";
            this.lb_Me_S.Size = new System.Drawing.Size(57, 15);
            this.lb_Me_S.TabIndex = 6;
            this.lb_Me_S.Text = "가위 수";
            // 
            // lb_Com_S
            // 
            this.lb_Com_S.AutoSize = true;
            this.lb_Com_S.Location = new System.Drawing.Point(155, 222);
            this.lb_Com_S.Name = "lb_Com_S";
            this.lb_Com_S.Size = new System.Drawing.Size(57, 15);
            this.lb_Com_S.TabIndex = 7;
            this.lb_Com_S.Text = "가위 수";
            // 
            // lb_Me_R
            // 
            this.lb_Me_R.AutoSize = true;
            this.lb_Me_R.Location = new System.Drawing.Point(22, 255);
            this.lb_Me_R.Name = "lb_Me_R";
            this.lb_Me_R.Size = new System.Drawing.Size(57, 15);
            this.lb_Me_R.TabIndex = 8;
            this.lb_Me_R.Text = "바위 수";
            // 
            // lb_Com_R
            // 
            this.lb_Com_R.AutoSize = true;
            this.lb_Com_R.Location = new System.Drawing.Point(155, 255);
            this.lb_Com_R.Name = "lb_Com_R";
            this.lb_Com_R.Size = new System.Drawing.Size(57, 15);
            this.lb_Com_R.TabIndex = 9;
            this.lb_Com_R.Text = "바위 수";
            // 
            // lb_Me_P
            // 
            this.lb_Me_P.AutoSize = true;
            this.lb_Me_P.Location = new System.Drawing.Point(22, 288);
            this.lb_Me_P.Name = "lb_Me_P";
            this.lb_Me_P.Size = new System.Drawing.Size(42, 15);
            this.lb_Me_P.TabIndex = 10;
            this.lb_Me_P.Text = "보 수";
            // 
            // lb_Com_P
            // 
            this.lb_Com_P.AutoSize = true;
            this.lb_Com_P.Location = new System.Drawing.Point(155, 288);
            this.lb_Com_P.Name = "lb_Com_P";
            this.lb_Com_P.Size = new System.Drawing.Size(42, 15);
            this.lb_Com_P.TabIndex = 11;
            this.lb_Com_P.Text = "보 수";
            // 
            // mhy_가위바위보
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(352, 353);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.btn_View_Result);
            this.Controls.Add(this.bo);
            this.Controls.Add(this.bawei);
            this.Controls.Add(this.gawei);
            this.Controls.Add(this.pictureBox2);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.result);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.MaximumSize = new System.Drawing.Size(650, 400);
            this.MinimumSize = new System.Drawing.Size(370, 400);
            this.Name = "mhy_가위바위보";
            this.Text = "mhy_가위바위보";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label result;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.Button gawei;
        private System.Windows.Forms.Button bawei;
        private System.Windows.Forms.Button bo;
        private System.Windows.Forms.Button btn_View_Result;
        private System.Windows.Forms.Timer Timer_View_Result;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label lb_Com_P;
        private System.Windows.Forms.Label lb_Me_P;
        private System.Windows.Forms.Label lb_Com_R;
        private System.Windows.Forms.Label lb_Me_R;
        private System.Windows.Forms.Label lb_Com_S;
        private System.Windows.Forms.Label lb_Me_S;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label lb_Total_Count;
        private System.Windows.Forms.Label lb_Draw_Score;
        private System.Windows.Forms.Label lb_Com_Score;
        private System.Windows.Forms.Label lb_Me_Score;
    }
}

