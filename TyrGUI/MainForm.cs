using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace TyrGUI
{
	public partial class MainForm : Form
	{
		private Client _client;
		private Thread _clientThread;
		private bool _connected;

		public MainForm()
		{
			InitializeComponent();
		}

		private void MainForm_Load( object sender, EventArgs e )
		{
			_client = new Client();
			
			Backlog.OnMessageAdded += OnBacklogMessageAdded;
		}

		private void connect_btn_connect_Click( object sender, EventArgs e )
		{
			if( _connected )
				Disconnect();
			else
				Connect();
		}

		private void Connect()
		{
			_connected = _client.Connect( connect_txt_ip.Text, int.Parse( connect_txt_port.Text ) );

			if( _connected )
			{
				connect_btn_connect.Text = "Disconnect";

				_clientThread = new Thread( new ThreadStart( UpdateClient ) );
				_clientThread.IsBackground = true;
				_clientThread.Start();
			}
		}

		private void Disconnect()
		{
			_client.Disconnect();

			connect_btn_connect.Text = "Connect";
		}

		private void UpdateClient()
		{
			bool connected = _connected;
			while( connected )
			{
				connected = _client.PollBacklog();

				Thread.Sleep( 1000 );
			}

			if( _connected )
			{
				Invoke( (MethodInvoker)delegate { Disconnect(); } );
			}
		}

		private void OnBacklogMessageAdded( LogMessage message )
		{
			Invoke( (MethodInvoker) delegate
			{
				console_txt_console.AppendText( message.message + Environment.NewLine );
			} );
		}
	}
}
