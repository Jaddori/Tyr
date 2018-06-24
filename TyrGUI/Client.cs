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
		public const int MAX_BUF_LEN = 512;

		private Socket _socket;

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
			}

			return result;
		}

		public void Disconnect()
		{
			_socket.Shutdown( SocketShutdown.Receive );
		}

		public bool PollBacklog()
		{
			/*byte[] buffer = new byte[MAX_BUF_LEN];

			int recvbytes = 0;
			try
			{
				recvbytes = _socket.Receive( buffer );

				if( recvbytes > 0 )
				{
					int readBytes = 0;
					while( readBytes < recvbytes )
					{
						byte length = buffer[readBytes++];
						length = (byte)(length - 1);

						string message = Encoding.ASCII.GetString( buffer, readBytes, length );

						readBytes += length;

						LogMessage logMessage = new LogMessage()
						{
							message = message,
							timestamp = DateTime.Now,
						};

						Backlog.Add( logMessage );
					}
				}
			}
			catch( SocketException e )
			{
				_socket.Shutdown( SocketShutdown.Receive );
				return false;
			}*/

			List<byte> bytes = new List<byte>();

			try
			{
				int recvbytes = 0;
				int end = 1;
				while( end > recvbytes )
				{
					byte[] tempBuffer = new byte[MAX_BUF_LEN];
					recvbytes = _socket.Receive( tempBuffer );

					byte[] finalBuffer = null;
					if( recvbytes < MAX_BUF_LEN )
					{
						finalBuffer = new byte[recvbytes];
						Array.Copy( tempBuffer, finalBuffer, recvbytes );
					}
					else
						finalBuffer = tempBuffer;

					bytes.AddRange( finalBuffer );

					// validate that we got all the data that was sent
					end = 0;
					while( end < recvbytes )
					{
						byte length = (byte)( tempBuffer[end++] - 1 );
						end += length;
					}
				}
			}
			catch( SocketException e )
			{
				_socket.Shutdown( SocketShutdown.Receive );
				return false;
			}

			byte[] buffer = bytes.ToArray();
			int bufferSize = buffer.Length;

			int readBytes = 0;
			while( readBytes < bufferSize )
			{
				byte length = (byte)( buffer[readBytes++] - 1 );
				
				string message = Encoding.ASCII.GetString( buffer, readBytes, length );
				readBytes += length;

				LogMessage logMessage = new LogMessage()
				{
					message = message,
					timestamp = DateTime.Now
				};

				Backlog.Add( logMessage );
			}

			return true;
		}
	}
}
