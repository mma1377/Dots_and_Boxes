#pragma once
#include "Game_Table.h"

namespace Dots_and_Boxes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Main_Menu
	/// </summary>
	public ref class Main_Menu : public System::Windows::Forms::Form
	{
	public:
		Main_Menu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main_Menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  start_game_btn;
	private: System::Windows::Forms::RadioButton^  player_start_first_radio;
	private: System::Windows::Forms::RadioButton^  bot_start_first_radio;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TrackBar^  game_size_track_bar;

	private: System::Windows::Forms::Button^  button1;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->start_game_btn = (gcnew System::Windows::Forms::Button());
			this->player_start_first_radio = (gcnew System::Windows::Forms::RadioButton());
			this->bot_start_first_radio = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->game_size_track_bar = (gcnew System::Windows::Forms::TrackBar());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->game_size_track_bar))->BeginInit();
			this->SuspendLayout();
			// 
			// start_game_btn
			// 
			this->start_game_btn->Cursor = System::Windows::Forms::Cursors::Default;
			this->start_game_btn->Location = System::Drawing::Point(171, 218);
			this->start_game_btn->Name = L"start_game_btn";
			this->start_game_btn->Size = System::Drawing::Size(101, 31);
			this->start_game_btn->TabIndex = 0;
			this->start_game_btn->Text = L"Let\'s Play";
			this->start_game_btn->UseVisualStyleBackColor = true;
			this->start_game_btn->Click += gcnew System::EventHandler(this, &Main_Menu::start_game_btn_Click);
			// 
			// player_start_first_radio
			// 
			this->player_start_first_radio->AutoSize = true;
			this->player_start_first_radio->ForeColor = System::Drawing::Color::RoyalBlue;
			this->player_start_first_radio->Location = System::Drawing::Point(16, 132);
			this->player_start_first_radio->Name = L"player_start_first_radio";
			this->player_start_first_radio->Size = System::Drawing::Size(54, 17);
			this->player_start_first_radio->TabIndex = 1;
			this->player_start_first_radio->TabStop = true;
			this->player_start_first_radio->Text = L"Player";
			this->player_start_first_radio->UseVisualStyleBackColor = true;
			// 
			// bot_start_first_radio
			// 
			this->bot_start_first_radio->AutoSize = true;
			this->bot_start_first_radio->ForeColor = System::Drawing::Color::Tomato;
			this->bot_start_first_radio->Location = System::Drawing::Point(16, 155);
			this->bot_start_first_radio->Name = L"bot_start_first_radio";
			this->bot_start_first_radio->Size = System::Drawing::Size(41, 17);
			this->bot_start_first_radio->TabIndex = 2;
			this->bot_start_first_radio->TabStop = true;
			this->bot_start_first_radio->Text = L"Bot";
			this->bot_start_first_radio->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 106);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Who will start the game\?";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Game Size";
			// 
			// game_size_track_bar
			// 
			this->game_size_track_bar->Location = System::Drawing::Point(92, 36);
			this->game_size_track_bar->Minimum = 2;
			this->game_size_track_bar->Name = L"game_size_track_bar";
			this->game_size_track_bar->Size = System::Drawing::Size(104, 45);
			this->game_size_track_bar->TabIndex = 5;
			this->game_size_track_bar->Value = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 178);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 28);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Change color";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// Main_Menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->game_size_track_bar);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->bot_start_first_radio);
			this->Controls->Add(this->player_start_first_radio);
			this->Controls->Add(this->start_game_btn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Main_Menu";
			this->Text = L"Main_Menu";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->game_size_track_bar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void start_game_btn_Click(System::Object^  sender, System::EventArgs^  e) {
		Dots_and_Boxes::Game_Table game_table(game_size_track_bar->Value);
		this->Hide();
		game_table.ShowDialog();
	}
};
}
