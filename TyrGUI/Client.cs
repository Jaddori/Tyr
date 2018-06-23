using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using System.Windows.Forms;

namespace TyrGUI
{
	public class Client
	{
		public const int DEFAULT_PORT = 15015;

		private Socket _socket;
		private int _port;

		public Client()
		{
		}

		public bool Connect(string ip, int port)
		{
			bool result = false;

			_socket = new Socket( AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp );

			_socket.Connect( ip, port );
			if( _socket.Connected )
			{
				result = true;

				byte[] buf = Encoding.ASCII.GetBytes( "Hejsan" );
				_socket.Send( buf );

				byte[] message = new byte[64];
				int recvbyte = _socket.Receive( message );
				string reply = Encoding.ASCII.GetString( message );

				_socket.Shutdown( SocketShutdown.Receive );

				MessageBox.Show( "Server said: " + reply );
			}

			return result;
		}
	}
}
