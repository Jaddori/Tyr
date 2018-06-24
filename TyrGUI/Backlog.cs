using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TyrGUI
{
	public struct LogMessage
	{
		public string message;
		public DateTime timestamp;
	}

	public static class Backlog
	{
		public delegate void MessageAddedEventHandler( LogMessage message ); 

		private static List<LogMessage> _messages = new List<LogMessage>();

		public static List<LogMessage> Messages => _messages;
		
		public static event MessageAddedEventHandler OnMessageAdded;
		
		public static void Add( LogMessage message )
		{
			_messages.Add( message );

			if( OnMessageAdded != null )
				OnMessageAdded( message );
		}
	}
}
