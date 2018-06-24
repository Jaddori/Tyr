namespace TyrGUI
{
	partial class MainForm
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose( bool disposing )
		{
			if( disposing && ( components != null ) )
			{
				components.Dispose();
			}
			base.Dispose( disposing );
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.tab_main = new System.Windows.Forms.TabControl();
			this.tab_connection = new System.Windows.Forms.TabPage();
			this.connect_txt_port = new System.Windows.Forms.TextBox();
			this.connect_lbl_port = new System.Windows.Forms.Label();
			this.connect_txt_password = new System.Windows.Forms.TextBox();
			this.connect_btn_connect = new System.Windows.Forms.Button();
			this.connect_lbl_password = new System.Windows.Forms.Label();
			this.connect_txt_ip = new System.Windows.Forms.TextBox();
			this.connect_lbl_ip = new System.Windows.Forms.Label();
			this.tab_progress = new System.Windows.Forms.TabPage();
			this.tab_console = new System.Windows.Forms.TabPage();
			this.console_txt_console = new System.Windows.Forms.TextBox();
			this.tab_main.SuspendLayout();
			this.tab_connection.SuspendLayout();
			this.tab_console.SuspendLayout();
			this.SuspendLayout();
			// 
			// tab_main
			// 
			this.tab_main.Controls.Add(this.tab_connection);
			this.tab_main.Controls.Add(this.tab_progress);
			this.tab_main.Controls.Add(this.tab_console);
			this.tab_main.Dock = System.Windows.Forms.DockStyle.Fill;
			this.tab_main.Location = new System.Drawing.Point(0, 0);
			this.tab_main.Name = "tab_main";
			this.tab_main.SelectedIndex = 0;
			this.tab_main.Size = new System.Drawing.Size(284, 262);
			this.tab_main.TabIndex = 0;
			// 
			// tab_connection
			// 
			this.tab_connection.Controls.Add(this.connect_txt_port);
			this.tab_connection.Controls.Add(this.connect_lbl_port);
			this.tab_connection.Controls.Add(this.connect_txt_password);
			this.tab_connection.Controls.Add(this.connect_btn_connect);
			this.tab_connection.Controls.Add(this.connect_lbl_password);
			this.tab_connection.Controls.Add(this.connect_txt_ip);
			this.tab_connection.Controls.Add(this.connect_lbl_ip);
			this.tab_connection.Location = new System.Drawing.Point(4, 22);
			this.tab_connection.Name = "tab_connection";
			this.tab_connection.Padding = new System.Windows.Forms.Padding(3);
			this.tab_connection.Size = new System.Drawing.Size(276, 236);
			this.tab_connection.TabIndex = 0;
			this.tab_connection.Text = "Connect";
			this.tab_connection.UseVisualStyleBackColor = true;
			// 
			// connect_txt_port
			// 
			this.connect_txt_port.Location = new System.Drawing.Point(191, 19);
			this.connect_txt_port.Name = "connect_txt_port";
			this.connect_txt_port.Size = new System.Drawing.Size(77, 20);
			this.connect_txt_port.TabIndex = 6;
			this.connect_txt_port.Text = "15015";
			// 
			// connect_lbl_port
			// 
			this.connect_lbl_port.AutoSize = true;
			this.connect_lbl_port.Location = new System.Drawing.Point(190, 3);
			this.connect_lbl_port.Name = "connect_lbl_port";
			this.connect_lbl_port.Size = new System.Drawing.Size(29, 13);
			this.connect_lbl_port.TabIndex = 5;
			this.connect_lbl_port.Text = "Port:";
			// 
			// connect_txt_password
			// 
			this.connect_txt_password.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.connect_txt_password.Location = new System.Drawing.Point(6, 58);
			this.connect_txt_password.Name = "connect_txt_password";
			this.connect_txt_password.PasswordChar = '*';
			this.connect_txt_password.Size = new System.Drawing.Size(262, 20);
			this.connect_txt_password.TabIndex = 4;
			// 
			// connect_btn_connect
			// 
			this.connect_btn_connect.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.connect_btn_connect.Location = new System.Drawing.Point(193, 84);
			this.connect_btn_connect.Name = "connect_btn_connect";
			this.connect_btn_connect.Size = new System.Drawing.Size(75, 23);
			this.connect_btn_connect.TabIndex = 3;
			this.connect_btn_connect.Text = "Connect";
			this.connect_btn_connect.UseVisualStyleBackColor = true;
			this.connect_btn_connect.Click += new System.EventHandler(this.connect_btn_connect_Click);
			// 
			// connect_lbl_password
			// 
			this.connect_lbl_password.AutoSize = true;
			this.connect_lbl_password.Location = new System.Drawing.Point(8, 42);
			this.connect_lbl_password.Name = "connect_lbl_password";
			this.connect_lbl_password.Size = new System.Drawing.Size(56, 13);
			this.connect_lbl_password.TabIndex = 2;
			this.connect_lbl_password.Text = "Password:";
			// 
			// connect_txt_ip
			// 
			this.connect_txt_ip.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.connect_txt_ip.Location = new System.Drawing.Point(6, 19);
			this.connect_txt_ip.Name = "connect_txt_ip";
			this.connect_txt_ip.Size = new System.Drawing.Size(179, 20);
			this.connect_txt_ip.TabIndex = 1;
			this.connect_txt_ip.Text = "127.0.0.1";
			// 
			// connect_lbl_ip
			// 
			this.connect_lbl_ip.AutoSize = true;
			this.connect_lbl_ip.Location = new System.Drawing.Point(8, 3);
			this.connect_lbl_ip.Name = "connect_lbl_ip";
			this.connect_lbl_ip.Size = new System.Drawing.Size(20, 13);
			this.connect_lbl_ip.TabIndex = 0;
			this.connect_lbl_ip.Text = "IP:";
			// 
			// tab_progress
			// 
			this.tab_progress.Location = new System.Drawing.Point(4, 22);
			this.tab_progress.Name = "tab_progress";
			this.tab_progress.Padding = new System.Windows.Forms.Padding(3);
			this.tab_progress.Size = new System.Drawing.Size(276, 236);
			this.tab_progress.TabIndex = 1;
			this.tab_progress.Text = "Progress";
			this.tab_progress.UseVisualStyleBackColor = true;
			// 
			// tab_console
			// 
			this.tab_console.Controls.Add(this.console_txt_console);
			this.tab_console.Location = new System.Drawing.Point(4, 22);
			this.tab_console.Name = "tab_console";
			this.tab_console.Padding = new System.Windows.Forms.Padding(3);
			this.tab_console.Size = new System.Drawing.Size(276, 236);
			this.tab_console.TabIndex = 2;
			this.tab_console.Text = "Console";
			this.tab_console.UseVisualStyleBackColor = true;
			// 
			// console_txt_console
			// 
			this.console_txt_console.BackColor = System.Drawing.SystemColors.MenuText;
			this.console_txt_console.Dock = System.Windows.Forms.DockStyle.Fill;
			this.console_txt_console.ForeColor = System.Drawing.Color.LawnGreen;
			this.console_txt_console.Location = new System.Drawing.Point(3, 3);
			this.console_txt_console.Multiline = true;
			this.console_txt_console.Name = "console_txt_console";
			this.console_txt_console.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
			this.console_txt_console.Size = new System.Drawing.Size(270, 230);
			this.console_txt_console.TabIndex = 0;
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(284, 262);
			this.Controls.Add(this.tab_main);
			this.Name = "MainForm";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Tyr";
			this.Load += new System.EventHandler(this.MainForm_Load);
			this.tab_main.ResumeLayout(false);
			this.tab_connection.ResumeLayout(false);
			this.tab_connection.PerformLayout();
			this.tab_console.ResumeLayout(false);
			this.tab_console.PerformLayout();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.TabControl tab_main;
		private System.Windows.Forms.TabPage tab_connection;
		private System.Windows.Forms.TextBox connect_txt_password;
		private System.Windows.Forms.Button connect_btn_connect;
		private System.Windows.Forms.Label connect_lbl_password;
		private System.Windows.Forms.TextBox connect_txt_ip;
		private System.Windows.Forms.Label connect_lbl_ip;
		private System.Windows.Forms.TabPage tab_progress;
		private System.Windows.Forms.TabPage tab_console;
		private System.Windows.Forms.TextBox console_txt_console;
		private System.Windows.Forms.TextBox connect_txt_port;
		private System.Windows.Forms.Label connect_lbl_port;
	}
}

