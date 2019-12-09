#pragma once

namespace P76081108HW4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// TickTacToe 的摘要
	/// </summary>
	public ref class TickTacToe : public System::Windows::Forms::Form
	{

		private: System::Windows::Forms::StatusStrip^  statusStrip_player;
		private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel_player;
		private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel_position;
		private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel_nowplayer;
		private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel_current_position;
		
		//自己加的控制變數
		array<Button^>^btn = gcnew array<Button^>(9);
		DateTime time_start = DateTime::Now;
		int flag = 0;//判斷是要下O還是X
		int count = 0;//count紀錄等一下是要按start還是stop 偶數:按start 奇數:按stop
		int draw = 0;//紀錄下了幾次 
		int nowplayer = 0;//紀錄目前玩家是哪位0:玩家1 1:玩家2
		

	public:

		TickTacToe(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
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
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
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
			this->groupbox_first->Text = L"先手(O)";
			// 
			// radioButton_player2
			// 
			this->radioButton_player2->AutoSize = true;
			this->radioButton_player2->Location = System::Drawing::Point(6, 43);
			this->radioButton_player2->Name = L"radioButton_player2";
			this->radioButton_player2->Size = System::Drawing::Size(53, 16);
			this->radioButton_player2->TabIndex = 1;
			this->radioButton_player2->Text = L"玩家2";
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
			this->radioButton_player1->Text = L"玩家1";
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
			this->toolStripStatusLabel_player->Text = L"玩家";
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
			this->toolStripStatusLabel_position->Text = L"滑鼠目前位置:";
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
				//動態產生9個按鈕
				btn[i] = gcnew Button();
				btn[i]->Width = 150;
				btn[i]->Height = 150;
				btn[i]->Click += gcnew System::EventHandler(this, &TickTacToe::TickTacToe_Click);
				btn[i]->Enabled = false;
				game_board_pnl->Controls->Add(btn[i]);
				//當滑鼠移到按鈕上時在下方StatusStrip顯示目前按鈕位置
				btn[i]->MouseHover += gcnew System::EventHandler(this, &TickTacToe::btn_MouseHover);
				//當滑鼠離開按鈕時在下方StatusStrip清除目前按鈕位置的string,否則會累加
				btn[i]->MouseLeave += gcnew System::EventHandler(this, &TickTacToe::btn_MouseLeave);
			}
		}
		private: System::Void TickTacToe_Click(System::Object^  sender, System::EventArgs^  e) {
		
			//要確認按到的是button才開始做事,否則會出現轉換error
			if (sender == btn[0] ||sender == btn[1] ||sender == btn[2] ||
				sender == btn[3] ||sender == btn[4] ||sender == btn[5] ||
				sender == btn[6] ||sender == btn[7] ||sender == btn[8])
			{
				Button^ bt = (Button^)sender;
				//換O下
				if (flag == 0)
				{
					//設定字型
					bt->Text = L"O";
					bt->Font = gcnew System::Drawing::Font("TimesNewRoman", 48, FontStyle::Bold);
					//下一次換X下
					flag = 1;
				}
				//換X下
				else
				{
					//設定字型
					bt->Text = L"X";
					bt->Font = gcnew System::Drawing::Font("TimesNewRoman", 48, FontStyle::Bold);
					//下一次換O下
					flag = 0;
				}
				//disable該btn 不讓它再被按
				bt->Enabled = false;

				draw++;
				//每下一步就確認是否有人贏?
				check();

				//換下一個玩家
				nowplayer = (nowplayer + 1) % 2;
				toolStripStatusLabel_nowplayer->Text = (nowplayer + 1).ToString();

				//下手數==9還沒分出勝負就代表平手
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
					//下手數清0
					draw = 0;
				}
			}
		}
		private: System::Void btn_start_stop_Click(System::Object^  sender, System::EventArgs^  e) {
			
			//count為偶數代表目前是要按start
			if (count % 2 == 0)
			{
				//每次都是OXOX這樣O先下
				flag = 0;
				//設定先手是玩家1還是玩家2
				if (radioButton_player1->Checked == true)
					nowplayer = 0;
				else
					nowplayer = 1;
				toolStripStatusLabel_nowplayer->Text = (nowplayer + 1).ToString();
				
				//重新設定btn
				for (int i = 0; i < 9; i++)
				{
					btn[i]->Enabled = true;
					btn[i]->Text = "";
				}
				//disable radiobutton
				radioButton_player1->Enabled = false;
				radioButton_player2->Enabled = false;
				
				//開始計時
				time_start = DateTime::Now;
				Lbl_Time->Text = (time_start - time_start).ToString();
				timer_game->Enabled = true;
				
				//start按下去下次是按stop
				btn_start_stop->Text = L"Stop";
				count++;

				//要將下手數清0
				draw = 0;
			}
			//count為奇數代表目前是要按stop
			else
			{
				//disable所有btn
				for (int i = 0; i < 9; i++)
					btn[i]->Enabled = false;
				
				//可以重新再選先手玩家
				radioButton_player1->Enabled = true;
				radioButton_player2->Enabled = true;
				
				//計時器停止計時
				timer_game->Enabled = false;
				
				//stop按下去下次變成是按start
				btn_start_stop->Text = L"Start";
				count++;
			}
		}
		void check()//判斷O or X是否滿足勝利條件
		{
			//For Rows
			
			//第一列連成一線
			if (btn[0]->Text == btn[1]->Text && btn[1]->Text == btn[2]->Text && btn[0]->Text != "")
			{
				//計時停止
				timer_game->Enabled = false;
				
				//show出message box O還是X誰贏了
				MessageBox::Show(btn[0]->Text + " Wins");
				
				//恢復到程式剛開始的樣子
				//btn清掉下棋痕跡
				for (int i = 0; i < 9; i++)
				{
					btn[i]->Enabled = false;
					btn[i]->Text = "";
				}
				//可以重新選誰先手
				radioButton_player1->Enabled = true;
				radioButton_player2->Enabled = true;
				//變成Start btn
				btn_start_stop->Text = L"Start";
				count++;
				//下手數清0
				draw = 0;
			}

			//第二列連成一線
			//處理模式同上
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
			
			//第三列連成一線
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
			
			//第一行連成一線
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
			
			//第二行連成一線
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
			
			//第三行連成一線
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
			
			//左上到右下的對角連成一線
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
			
			//左下到右上的對角連成一線
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
	//計時器顯示碼表計時
	private: System::Void timer_game_Tick(System::Object^  sender, System::EventArgs^  e) {
		DateTime now = DateTime::Now;
		Lbl_Time->Text = (now - time_start).ToString();
	}
	//show出目前滑鼠所在哪個btn?
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
	//滑鼠離開btn時清掉text
	private: System::Void btn_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		toolStripStatusLabel_current_position->Text = L"";
	}
};
}
