#ifndef ASTEROIDS_FORWARD_DECLARATIONS_H
#define ASTEROIDS_FORWARD_DECLARATIONS_H


///	Asteroids is the main namespace, under which all packages are found
namespace Asteroids
{
	///	Domain Layer
	namespace Domain
	{
		///	Hold the main Factory, that generates more specific factories in other packages
		namespace Factory
		{
			//
			class Factory;
			class FactoryInterface;
		}
		
		///	The Game package holds things related to playing the game
		/**
			ie the Actors (GunShip, Bullet, Rocks, etc), and other helpers
		*/
		namespace Game
		{
			//
			class Game;
			class GameInterface;
			
			//
			class GameHistoryInterface;
			class GameHistory;
			class GAME_HISTORY_ENTRY_INTERFACE;
			class GAME_HISTORY_ENTRY;
			
			//
			class Randomer;
			
			///	Not really a package so much as a way to organize allll the Actor classes and helpers away from the Game logic classes
			namespace Actors
			{
				class ActorInterface;
				class Actor;
				class GunShip;
				class Bullet;
				class Rock;
				class Alien;
				
				class Rect;
				class Vector;
			}
			
			//
			class GameFactory;
			class GameFactoryInterface;
		}
		
		///	The Net package holds things that help a client communicate with the server.
		/**
			Eventually this might also include things that help a server accept connections and communicate too (maybe)
		*/
		namespace Net
		{
			//
			class NetFactory;
			class NetFactoryInterface;
			
			//
			class ClientServerCommunicatorInterface;
			class ClientServerCommunicator;
			
			///	The Authentication namespace just holds stuff related to authenticating the client with the server
			namespace Authentication
			{
				//
				class Authenticator;
				class AuthenticationInterface;
			}
			
			///	The messages namespace just holds all the classes that function more as network data containers than functional classes.
			namespace Messages
			{
				//
				class AUTH_ATTEMPT;
				class AUTH_STATE;
				
				///	Just a way to keep the Enums in their own namespace so they won't collide with other stuff (perhaps)
				namespace Enums
				{
					//
					enum class ConnectionStatus;
				}
			}
		}
		
		///	The Server namespace holds stuff related to the Server executable
		/**
			ie: The Server class, the daemon, the server updater, and data structures you'd only get while sitting at the server
		*/
		namespace Server
		{
			//
			class ServerFactoryInterface;
			class ServerFactory;
			
			//
			class ServerDaemonInterface;
			class ServerDaemon;
			
			//
			class ServerUpdaterInterface;
			class ServerUpdater;
			
			//
			class HACCS_REPORT_INTERFACE;
			class HACCS_REPORT;
			class HACCS_REPORT_ACTIVITY_INTERFACE;
			class HACCS_REPORT_ACTIVITY;
		}
		
		///	The Store namespace holds things related to the Store
		/**
			So far this is just things the Client executable would use
		*/
		namespace Store
		{
			//
			class StoreFactory;
			class StoreFactoryInterface;
			
			//
			class Store;
			class StoreInterface;
			
			//
			class STORE_ITEM;
			class STORE_ITEM_INTERFACE;
			
			//
			class PaymentHelperInterface;
			class PaymentHelper;
			
			//
			class PAYMENT_RESULT_DETAILS_INTERFACE;
			class PAYMENT_RESULT_DETAILS;
			
			//
			class POWERUP_ADDED_INFO_INTERFACE;
			class POWERUP_ADDED_INFO;
			
			///	Just a way to keep the Enums in their own namespace so they won't collide with other stuff (perhaps)
			namespace Enums
			{
				//
				enum class CurrencyType;
				enum class PaymentMethod;
			}
		}
	}
	
	/// Holds Technical Services
	namespace TechnicalServices
	{
		//
		class TechnicalServicesFactoryInterface;
		class TechnicalServicesFactory;
		
		///	Package to help with persistence (ie database)
		namespace Persistence
		{
			//
			class DatabaserInterface;
			class Databaser;
		}
		
		///	Package to help with external Financial services
		namespace Financial
		{
			//
			class FinancialServicesInterface;
			class FinancialServices;
			
			//
			class CreditCardProcessorInterface;
			class MastercardProcessor;
			class VisaProcessor;
		}
		
		///	Package to hold social media related stuffs
		namespace Social
		{
			//
			class SocialMediaInterface;
			class SocialMedia;
			
			//
			class FRIEND_ON_SOCIAL_MEDIA_INTERFACE;
			class FRIEND_ON_SOCIAL_MEDIA;
		}
	}
	
	///	The UI namespace holds things related to User Interfaces
	/**
		So far just the ClientTextUI package and the ServerTextUI package
	*/
	namespace UI
	{
		//
		class UIFactoryInterface;
		class UIFactory;
		
		///	Holds things related to the client text user interface
		namespace ClientTextUI
		{
			//
			class ClientTextUIInterface;
			class ClientTextUI;
			
			//
			class Input;
			class DisplayGrid;
			
			///	Just a way to keep the Enums in their own namespace so they won't collide with other stuff (perhaps)
			namespace Enums
			{
				//
				enum class MainMenuChoice;
			}
		}
		
		///	Holds things related to the server tex user interface
		namespace ServerTextUI
		{
			//
			class ServerTextUIInterface;
			class ServerTextUI;
			
			///	Just a way to keep the Enums in their own namespace so they won't collide with other stuff (perhaps)
			namespace Enums
			{
				//
				enum class MainMenuChoice;
			}
		}
	}
}







#endif
