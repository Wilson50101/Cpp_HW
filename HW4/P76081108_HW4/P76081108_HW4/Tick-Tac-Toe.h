#pragma once

namespace P76081108HW4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// TickTacToe ���K�n
	/// </summary>
	public ref class TickTacToe : public System::Windows::Forms::Form
	{

		private: System::Windows::Forms::StatusStrip^  statusStrip_player;
		private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel_player;
		private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel_position;
		private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel_nowplayer;
		private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel_current_position;
		
		//�ۤv�[�������ܼ�
		array<Button^>^btn = gcnew array<Button^>(9);
		DateTime time_start = DateTime::Now;
		int flag = 0;//�P�_�O�n�UO�٬OX
		int count = 0;//count�������@�U�O�n��start�٬Ostop ����:��start �_��:��stop
		int draw = 0;//�����U�F�X�� 
		int nowplayer = 0;//�����ثe���a�O����0:���a1 1:���a2
		

	public:

		TickTacToe(void)
		{
			InitializeComponent();
			//
			//TODO:  �b���[�J�غc�禡�{���X
			//
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~TickTacToe()
		{
			if (components)
			{
				delete components;
			}
		}
		private: System::Windows::Forms::FlowLayoutPanel^  game_board_pnl;
		private: System::Windows::Forms::GroupBox^  groupbox_first;
		private: System::Windows::Forms::RadioButton^  radioButton_player2;

		private: System::Windows::Forms::RadioButton^  radioButton_player1;
		private: System::Windows::Forms::Button^  btn_start_stop;
		private: System::Windows::Forms::Label^  Lbl_Time;
		private: System::Windows::Forms::Timer^  timer_game;
		private: System::ComponentModel::IContainer^  components;


		protected:

	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->game_board_pnl = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->groupbox_first = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton_player2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_player1 = (gcnew System::Windows::Forms::RadioButton());
			this->btn_start_stop = (gcnew System::Windows::Forms::Button());
			this->Lbl_Time = (gcnew System::Windows::Forms::Label());
			this->timer_game = (gcnew System::Windows::Forms::Timer(this->components));
			this->statusStrip_player = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel_player = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel_nowplayer = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel_position = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel_current_position = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->groupbox_first->SuspendLayout();
			this->statusStrip_player->SuspendLayout();
			this->SuspendLayout();
			// 
			// game_board_pnl
			// 
			this->game_board_pnl->BackColor = System::Drawing::Color::White;
			this->game_board_pnl->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->game_board_pnl->Location = System::Drawing::Point(12, 12);
			this->game_board_pnl->Name = L"game_board_pnl";
			this->game_board_pnl->Size = System::Drawing::Size(470, 470);
			this->game_board_pnl->TabIndex = 0;
			// 
			// groupbox_first
			// 
			this->groupbox_first->Controls->Add(this->radioButton_player2);
			this->groupbox_first->Controls->Add(this->radioButton_player1);
			this->groupbox_first->Location = System::Drawing::Point(488, 12);
			this->groupbox_first->Name = L"groupbox_first";
			this->groupbox_first->Size = System::Drawing::Size(138, 72);
			this->groupbox_first->TabIndex = 1;
			this->groupbox_first->TabStop = false;
			this->groupbox_first->Text = L"����(O)";
			// 
			// radioButton_player2
			// 
			this->radioButton_player2->AutoSize = true;
			this->radioButton_player2->Location = System::Drawing::Point(6, 43);
			this->radioButton_player2->Name = L"radioButton_player2";
			this->radioButton_player2->Size = System::Drawing::Size(53, 16);
			this->radioButton_player2->TabIndex = 1;
			this->radioButton_player2->Text = L"���a2";
			this->radioButton_player2->UseVisualStyleBackColor = true;
			// 
			// radioButton_player1
			// 
			this->radioButton_player1->AutoSize = true;
			this->radioButton_player1->Checked = true;
			this->radioButton_player1->Location = System::Drawing::Point(6, 21);
			this->radioButton_player1->Name = L"radioButton_player1";
			this->radioButton_player1->Size = System::Drawing::Size(53, 16);
			this->radioButton_player1->TabIndex = 0;
			this->radioButton_player1->TabStop = true;
			this->radioButton_player1->Text = L"���a1";
			this->radioButton_player1->UseVisualStyleBackColor = true;
			// 
			// btn_start_stop
			// 
			this->btn_start_stop->Location = System::Drawing::Point(488, 417);
			this->btn_start_stop->Name = L"btn_start_stop";
			this->btn_start_stop->Size = System::Drawing::Size(136, 23);
			this->btn_start_stop->TabIndex = 2;
			this->btn_start_stop->Text = L"Start";
			this->btn_start_stop->UseVisualStyleBackColor = true;
			this->btn_start_stop->Click += gcnew System::EventHandler(this, &TickTacToe::btn_start_stop_Click);
			// 
			// Lbl_Time
			// 
			this->Lbl_Time->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Lbl_Time->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Lbl_Time->Location = System::Drawing::Point(488, 461);
			this->Lbl_Time->Name = L"Lbl_Time";
			this->Lbl_Time->Size = System::Drawing::Size(136, 21);
			this->Lbl_Time->TabIndex = 3;
			// 
			// timer_game
			// 
			this->timer_game->Tick += gcnew System::EventHandler(this, &TickTacToe::timer_game_Tick);
			// 
			// statusStrip_player
			// 
			this->statusStrip_player->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->toolStripStatusLabel_player,
					this->toolStripStatusLabel_nowplayer, this->toolStripStatusLabel_position, this->toolStripStatusLabel_current_position
			});
			this->statusStrip_player->Location = System::Drawing::Point(0, 489);
			this->statusStrip_player->Name = L"statusStrip_player";
			this->statusStrip_player->Size = System::Drawing::Size(638, 22);
			this->statusStrip_player->TabIndex = 4;
			this->statusStrip_player->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel_player
			// 
			this->toolStripStatusLabel_player->Name = L"toolStripStatusLabel_player";
			this->toolStripStatusLabel_player->Size = System::Drawing::Size(31, 17);
			this->toolStripStatusLabel_player->Text = L"���a";
			// 
			// toolStripStatusLabel_nowplayer
			// 
			this->toolStripStatusLabel_nowplayer->Name = L"toolStripStatusLabel_nowplayer";
			this->toolStripStatusLabel_nowplayer->Size = System::Drawing::Size(0, 17);
			// 
			// toolStripStatusLabel_position
			// 
			this->toolStripStatusLabel_position->Name = L"toolStripStatusLabel_position";
			this->toolStripStatusLabel_position->Size = System::Drawing::Size(82, 17);
			this->toolStripStatusLabel_position->Text = L"�ƹ��ثe��m:";
			// 
			// toolStripStatusLabel_current_position
			// 
			this->toolStripStatusLabel_current_position->Name = L"toolStripStatusLabel_current_position";
			this->toolStripStatusLabel_current_position->Size = System::Drawing::Size(0, 17);
			// 
			// TickTacToe
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->ClientSize = System::Drawing::Size(638, 511);
			this->Controls->Add(this->statusStrip_player);
			this->Controls->Add(this->Lbl_Time);
			this->Controls->Add(this->btn_start_stop);
			this->Controls->Add(this->groupbox_first);
			this->Controls->Add(this->game_board_pnl);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Name = L"TickTacToe";
			this->Text = L"Tick-Tac-Toe";
			this->Load += gcnew System::EventHandler(this, &TickTacToe::TickTacToe_Load);
			this->Click += gcnew System::EventHandler(this, &TickTacToe::TickTacToe_Click);
			this->groupbox_first->ResumeLayout(false);
			this->groupbox_first->PerformLayout();
			this->statusStrip_player->ResumeLayout(false);
			this->statusStrip_player->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void TickTacToe_Load(System::Object^  sender, System::EventArgs^  e) {
			for (int i = 0; i < 9; i++)
			{
				//�ʺA����9�ӫ��s
				btn[i] = gcnew Button();
				btn[i]->Width = 150;
				btn[i]->Height = 150;
				btn[i]->Click += gcnew System::EventHandler(this, &TickTacToe::TickTacToe_Click);
				btn[i]->Enabled = false;
				game_board_pnl->Controls->Add(btn[i]);
				//��ƹ�������s�W�ɦb�U��StatusStrip��ܥثe���s��m
				btn[i]->MouseHover += gcnew System::EventHandler(this, &TickTacToe::btn_MouseHover);
				//��ƹ����}���s�ɦb�U��StatusStrip�M���ثe���s��m��string,�_�h�|�֥[
				btn[i]->MouseLeave += gcnew System::EventHandler(this, &TickTacToe::btn_MouseLeave);
			}
		}
		private: System::Void TickTacToe_Click(System::Object^  sender, System::EventArgs^  e) {
		
			//�n�T�{���쪺�Obutton�~�}�l����,�_�h�|�X�{�ഫerror
			if (sender == btn[0] ||sender == btn[1] ||sender == btn[2] ||
				sender == btn[3] ||sender == btn[4] ||sender == btn[5] ||
				sender == btn[6] ||sender == btn[7] ||sender == btn[8])
			{
				Button^ bt = (Button^)sender;
				//��O�U
				if (flag == 0)
				{
					//�]�w�r��
					bt->Text = L"O";
					bt->Font = gcnew System::Drawing::Font("TimesNewRoman", 48, FontStyle::Bold);
					//�U�@����X�U
					flag = 1;
				}
				//��X�U
				else
				{
					//�]�w�r��
					bt->Text = L"X";
					bt->Font = gcnew System::Drawing::Font("TimesNewRoman", 48, FontStyle::Bold);
					//�U�@����O�U
					flag = 0;
				}
				//disable��btn �������A�Q��
				bt->Enabled = false;

				draw++;
				//�C�U�@�B�N�T�{�O�_���HĹ?
				check();

				//���U�@�Ӫ��a
				nowplayer = (nowplayer + 1) % 2;
				toolStripStatusLabel_nowplayer->Text = (nowplayer + 1).ToString();

				//�U���==9�٨S���X�ӭt�N�N����
				if (draw == 9)
				{
					timer_game->Enabled = false;
					MessageBox::Show("Game Draw");
					for (int i = 0; i < 9; i++)
					{
						btn[i]->Enabled = false;
						btn[i]->Text = "";
					}
					radioButton_player1->Enabled = true;
					radioButton_player2->Enabled = true;
					btn_start_stop->Text = L"Start";
					//�U��ƲM0
					draw = 0;
				}
			}
		}
		private: System::Void btn_start_stop_Click(System::Object^  sender, System::EventArgs^  e) {
			
			//count�����ƥN��ثe�O�n��start
			if (count % 2 == 0)
			{
				//�C�����OOXOX�o��O���U
				flag = 0;
				//�]�w����O���a1�٬O���a2
				if (radioButton_player1->Checked == true)
					nowplayer = 0;
				else
					nowplayer = 1;
				toolStripStatusLabel_nowplayer->Text = (nowplayer + 1).ToString();
				
				//���s�]�wbtn
				for (int i = 0; i < 9; i++)
				{
					btn[i]->Enabled = true;
					btn[i]->Text = "";
				}
				//disable radiobutton
				radioButton_player1->Enabled = false;
				radioButton_player2->Enabled = false;
				
				//�}�l�p��
				time_start = DateTime::Now;
				Lbl_Time->Text = (time_start - time_start).ToString();
				timer_game->Enabled = true;
				
				//start���U�h�U���O��stop
				btn_start_stop->Text = L"Stop";
				count++;

				//�n�N�U��ƲM0
				draw = 0;
			}
			//count���_�ƥN��ثe�O�n��stop
			else
			{
				//disable�Ҧ�btn
				for (int i = 0; i < 9; i++)
					btn[i]->Enabled = false;
				
				//�i�H���s�A����⪱�a
				radioButton_player1->Enabled = true;
				radioButton_player2->Enabled = true;
				
				//�p�ɾ�����p��
				timer_game->Enabled = false;
				
				//stop���U�h�U���ܦ��O��start
				btn_start_stop->Text = L"Start";
				count++;
			}
		}
		void check()//�P�_O or X�O�_�����ӧQ����
		{
			//For Rows
			
			//�Ĥ@�C�s���@�u
			if (btn[0]->Text == btn[1]->Text && btn[1]->Text == btn[2]->Text && btn[0]->Text != "")
			{
				//�p�ɰ���
				timer_game->Enabled = false;
				
				//show�Xmessage box O�٬OX��Ĺ�F
				MessageBox::Show(btn[0]->Text + " Wins");
				
				//��_��{����}�l���ˤl
				//btn�M���U�Ѳ���
				for (int i = 0; i < 9; i++)
				{
					btn[i]->Enabled = false;
					btn[i]->Text = "";
				}
				//�i�H���s��֥���
				radioButton_player1->Enabled = true;
				radioButton_player2->Enabled = true;
				//�ܦ�Start btn
				btn_start_stop->Text = L"Start";
				count++;
				//�U��ƲM0
				draw = 0;
			}

			//�ĤG�C�s���@�u
			//�B�z�Ҧ��P�W
			if (btn[3]->Text == btn[4]->Text && btn[4]->Text == btn[5]->Text && btn[3]->Text != "")
			{
				timer_game->Enabled = false;
				MessageBox::Show(btn[3]->Text + " Wins");
				for (int i = 0; i < 9; i++)
				{
					btn[i]->Enabled = false;
					btn[i]->Text = "";
				}
				radioButton_player1->Enabled = true;
				radioButton_player2->Enabled = true;
				btn_start_stop->Text = L"Start";
				count++;
				draw = 0;
			}
			
			//�ĤT�C�s���@�u
			if (btn[6]->Text == btn[7]->Text && btn[7]->Text == btn[8]->Text && btn[6]->Text != "")
			{
				timer_game->Enabled = false;
				MessageBox::Show(btn[6]->Text + " Wins");
				for (int i = 0; i < 9; i++)
				{
					btn[i]->Enabled = false;
					btn[i]->Text = "";
				}
				radioButton_player1->Enabled = true;
				radioButton_player2->Enabled = true;
				btn_start_stop->Text = L"Start";
				count++;
				draw = 0;
			}
			//For Coloums
			
			//�Ĥ@��s���@�u
			if (btn[0]->Text == btn[3]->Text && btn[3]->Text == btn[6]->Text && btn[3]->Text != "")
			{
				timer_game->Enabled = false;
				MessageBox::Show(btn[0]->Text + " Wins");
				for (int i = 0; i < 9; i++)
				{
					btn[i]->Enabled = false;
					btn[i]->Text = "";
				}
				radioButton_player1->Enabled = true;
				radioButton_player2->Enabled = true;
				btn_start_stop->Text = L"Start";
				count++;
				draw = 0;
			}
			
			//�ĤG��s���@�u
			if (btn[1]->Text == btn[4]->Text && btn[4]->Text == btn[7]->Text && btn[1]->Text != "")
			{
				timer_game->Enabled = false;
				MessageBox::Show(btn[1]->Text + " Wins"); 
				for (int i = 0; i < 9; i++)
				{
					btn[i]->Enabled = false;
					btn[i]->Text = "";
				}
				radioButton_player1->Enabled = true;
				radioButton_player2->Enabled = true;
				btn_start_stop->Text = L"Start";
				count++;
				draw = 0;
			}
			
			//�ĤT��s���@�u
			if (btn[2]->Text == btn[5]->Text && btn[5]->Text == btn[8]->Text && btn[2]->Text != "")
			{
				timer_game->Enabled = false;
				MessageBox::Show(btn[2]->Text + " Wins");
				for (int i = 0; i < 9; i++)
				{
					btn[i]->Enabled = false;
					btn[i]->Text = "";
				}
				radioButton_player1->Enabled = true;
				radioButton_player2->Enabled = true;
				btn_start_stop->Text = L"Start";
				count++;
				draw = 0;
			}
			//For Diagnols
			
			//���W��k�U���﨤�s���@�u
			if (btn[0]->Text == btn[4]->Text && btn[4]->Text == btn[8]->Text && btn[0]->Text != "")
			{
				timer_game->Enabled = false;
				MessageBox::Show(btn[0]->Text + " Wins");
				for (int i = 0; i < 9; i++)
				{
					btn[i]->Enabled = false;
					btn[i]->Text = "";
				}
				radioButton_player1->Enabled = true;
				radioButton_player2->Enabled = true;
				btn_start_stop->Text = L"Start";
				count++;
				draw = 0;
			}
			
			//���U��k�W���﨤�s���@�u
			if (btn[2]->Text == btn[4]->Text && btn[4]->Text == btn[6]->Text && btn[2]->Text != "")
			{
				timer_game->Enabled = false;
				MessageBox::Show(btn[2]->Text + " Wins");
				for (int i = 0; i < 9; i++)
				{
					btn[i]->Enabled = false;
					btn[i]->Text = "";
				}
				radioButton_player1->Enabled = true;
				radioButton_player2->Enabled = true;
				btn_start_stop->Text = L"Start";
				count++;
				draw = 0;
			}
		}
	//�p�ɾ���ܽX��p��
	private: System::Void timer_game_Tick(System::Object^  sender, System::EventArgs^  e) {
		DateTime now = DateTime::Now;
		Lbl_Time->Text = (now - time_start).ToString();
	}
	//show�X�ثe�ƹ��Ҧb����btn?
	private: System::Void btn_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		if (sender==btn[0])
			toolStripStatusLabel_current_position->Text = "(1,1)";
		if (sender == btn[1])
			toolStripStatusLabel_current_position->Text = "(1,2)";
		if (sender == btn[2])
			toolStripStatusLabel_current_position->Text = "(1,3)";
		if (sender == btn[3])
			toolStripStatusLabel_current_position->Text = "(2,1)";
		if (sender == btn[4])
			toolStripStatusLabel_current_position->Text = "(2,2)";
		if (sender == btn[5])
			toolStripStatusLabel_current_position->Text = "(2,3)";
		if (sender == btn[6])
			toolStripStatusLabel_current_position->Text = "(3,1)";
		if (sender == btn[7])
			toolStripStatusLabel_current_position->Text = "(3,2)";
		if (sender == btn[8])
			toolStripStatusLabel_current_position->Text = "(3,3)";
	}
	//�ƹ����}btn�ɲM��text
	private: System::Void btn_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		toolStripStatusLabel_current_position->Text = L"";
	}
};
}
