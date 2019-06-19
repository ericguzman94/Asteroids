
# Reminder: Try to follow unison's pattern:
# src, build, and bin directories are all in the repo,
# so builds don't mess with the source tree or the user's outer dirs
# .gitignore for build/bin though


define say
$(info [Asteroids] $1)
endef


#
SRC_DIR=.
SRC_EXECUTABLES_DIR=$(SRC_DIR)
DOCS_DIR=../docs
DOCS_DEPLOY_HOSTNAME=hoth.sevencode.com
DOCS_DEPLOY_USERNAME=hoth
DOCS_DEPLOY_LOCAL_PATH=$(DOCS_DIR)/html/
DOCS_DEPLOY_REMOTE_PATH=/home/hoth/public_html/
BUILD_DIR=../build
BUILD_DIR_CORE=$(BUILD_DIR)/core
BUILD_DIR_SERVER=$(BUILD_DIR)/server
BUILD_DIR_CLIENT=$(BUILD_DIR)/client
BIN_DIR=../bin
SERVER_EXE_NAME=asteroids-server
SERVER_EXE_PATH=$(BIN_DIR)/$(SERVER_EXE_NAME)
CLIENT_EXE_NAME=asteroids-console-client
CLIENT_EXE_PATH=$(BIN_DIR)/$(CLIENT_EXE_NAME)


#	Commands file that GDB will use when running trace-play-game
GDB_TRACE_PLAY_GAME_COMMANDS_FILENAME=gdb-trace-play-game-commands
GDB_TRACE_PLAY_GAME_COMMANDS_SRC=gdb-trace-play-game-commands
GDB_TRACE_PLAY_GAME_COMMANDS_DEST=$(BIN_DIR)/gdb-trace-play-game-commands


#
CC=g++
CFLAGS= -c -I..
LINK_FLAGS=


#	Add professor's compilation flags
#	Remove -I. though
#CFLAGS  += -g3 -O0 -ansi -std=c++17 -pedantic -Wall -Wold-style-cast -Woverloaded-virtual -Wextra -I. -DUSING_TOMS_SUGGESTIONS
CFLAGS  += -g3 -O0 -ansi -std=c++17 -pedantic -Wall -Wold-style-cast -Woverloaded-virtual -Wextra -DUSING_TOMS_SUGGESTIONS


#	Add support for threads
LINK_FLAGS+= -pthread


#	If USE_LONG_ROCKS is defined, add to the compiler flags
ifeq ($(USE_LONG_ROCKS),)
$(call say,USE_LONG_ROCKS is not defined; Will only use square rocks)
else
$(call say,USE_LONG_ROCKS is defined: $(USE_LONG_ROCKS); Will use both square and long rocks)
CFLAGS += -DUSE_LONG_ROCKS 
endif


#	If USE_VISA is defined, add to the compiler flags
ifeq ($(USE_VISA),)
$(call say,USE_VISA is not defined; Keeping default payment processing at Mastercard)
else
$(call say,USE_VISA is defined: $(USE_VISA); Switching default payment processing to Visa)
CFLAGS += -DUSE_VISA
endif


#
default:	default-say
default:	help
default-say:
	$(call info,No target specified; Using default)
.PHONY:	default default-say


help:
	@echo
	@echo "make all			==> Call all important targets"
	@echo "make build			==> Build everything"
	@echo "run-server			==> Run the server executable"
	@echo "run-console-client		==> Run the console client executable"
	@echo "make exe			==> Build the main executables (Server and Client)"
	@echo "make trace-play-game		==> Run a debug trace for \"Play a Game\" Software Sequence Diagram"
	@echo
	@echo " -- "
	@echo "Define USE_LONG_ROCKS to turn on the LongRock actor class (for the polymorphic part of presentation)"
	@echo "Define USE_VISA to switch credit card processing to Visa (for polymorphic protected variation to interface; for presentation)"
	@echo
.PHONY: help


all:	all-say
all:	$(SERVER_EXE_PATH)
all:	$(CLIENT_EXE_PATH)
all:	docs
	$(info )
	$(call say,Done building everything)
all-say:
	$(info )
	$(call say,Running target 'all')
.PHONY: all all-say


#	Build stuff
build:	build-say
build:	$(SERVER_EXE_PATH) $(CLIENT_EXE_PATH)
build-say:
	$(info )
	$(call say,Building all objects)


#	Core compilation objects
CORE_OBJECTS=		\
					$(BUILD_DIR_CORE)/Domain_Server_ServerFactory.o \
					$(BUILD_DIR_CORE)/Domain_Server_ServerDaemon.o \
					$(BUILD_DIR_CORE)/Domain_Server_ServerUpdater.o \
					$(BUILD_DIR_CORE)/Domain_Server_HACCS_REPORT.o \
					$(BUILD_DIR_CORE)/Domain_Server_HACCS_REPORT_ACTIVITY.o \
					$(BUILD_DIR_CORE)/Domain_Factory_Factory.o \
					$(BUILD_DIR_CORE)/Domain_Game_Actors_Actor.o \
					$(BUILD_DIR_CORE)/Domain_Game_Actors_GunShip.o \
					$(BUILD_DIR_CORE)/Domain_Game_Actors_Bullet.o \
					$(BUILD_DIR_CORE)/Domain_Game_Actors_Rock.o \
					$(BUILD_DIR_CORE)/Domain_Game_Actors_LongRock.o \
					$(BUILD_DIR_CORE)/Domain_Game_Actors_Rect.o \
					$(BUILD_DIR_CORE)/Domain_Game_Actors_Vector.o \
					$(BUILD_DIR_CORE)/Domain_Game_Game.o \
					$(BUILD_DIR_CORE)/Domain_Game_GameFactory.o \
					$(BUILD_DIR_CORE)/Domain_Game_Randomer.o \
					$(BUILD_DIR_CORE)/Domain_Game_GameHistory.o \
					$(BUILD_DIR_CORE)/Domain_Game_GAME_HISTORY_ENTRY.o \
					$(BUILD_DIR_CORE)/Domain_Net_Authentication_Authenticator.o \
					$(BUILD_DIR_CORE)/Domain_Net_Factory_NetFactory.o \
					$(BUILD_DIR_CORE)/Domain_Net_Messages_AUTH_ATTEMPT.o \
					$(BUILD_DIR_CORE)/Domain_Net_Messages_AUTH_STATE.o \
					$(BUILD_DIR_CORE)/Domain_Net_ClientServerCommunicator.o \
					$(BUILD_DIR_CORE)/Domain_Store_StoreFactory.o \
					$(BUILD_DIR_CORE)/Domain_Store_Store.o \
					$(BUILD_DIR_CORE)/Domain_Store_STORE_ITEM.o \
					$(BUILD_DIR_CORE)/Domain_Store_PaymentHelper.o \
					$(BUILD_DIR_CORE)/Domain_Store_PAYMENT_RESULT_DETAILS.o \
					$(BUILD_DIR_CORE)/Domain_Store_POWERUP_ADDED_INFO.o \
					$(BUILD_DIR_CORE)/TechnicalServices_TechnicalServicesFactory.o \
					$(BUILD_DIR_CORE)/TechnicalServices_Persistence_Databaser.o \
					$(BUILD_DIR_CORE)/TechnicalServices_Financial_FinancialServices.o \
					$(BUILD_DIR_CORE)/TechnicalServices_Financial_VisaProcessor.o \
					$(BUILD_DIR_CORE)/TechnicalServices_Financial_MastercardProcessor.o \
					$(BUILD_DIR_CORE)/TechnicalServices_Social_SocialMedia.o \
					$(BUILD_DIR_CORE)/TechnicalServices_Social_FRIEND_ON_SOCIAL_MEDIA.o \
					$(BUILD_DIR_CORE)/UI_UIFactory.o \
					$(BUILD_DIR_CORE)/UI_ServerTextUI_ServerTextUI.o \
					$(BUILD_DIR_CORE)/UI_ClientTextUI_ClientTextUI.o \
					$(BUILD_DIR_CORE)/UI_ClientTextUI_DisplayGrid.o \
					$(BUILD_DIR_CORE)/UI_ClientTextUI_Input.o

#
$(DOCS_DIR):
	$(info )
	$(call say,Creating DOCS_DIR: $@)
	mkdir --parents "$@"

#
$(BUILD_DIR):
	$(info )
	$(call say,Creating BUILD_DIR: $@)
	mkdir --parents "$@"

#
$(BUILD_DIR_CORE):		| $(BUILD_DIR)
	$(info )
	$(call say,Creating BUILD_DIR_CORE: $@)
	mkdir --parents "$@"


#
$(BUILD_DIR_SERVER):	| $(BUILD_DIR)
	$(info )
	$(call say,Creating BUILD_DIR_SERVER: $@)
	mkdir --parents "$@"

#
$(BUILD_DIR_CLIENT):	| $(BUILD_DIR)
	$(info )
	$(call say,Creating BUILD_DIR_CLIENT: $@)
	mkdir --parents "$@"


$(BIN_DIR):
	$(info )
	$(call say,Creating BIN_DIR: $@)
	mkdir --parents "$@"


#	Server executable object
$(BUILD_DIR_SERVER)/Server.o:	\
			$(SRC_EXECUTABLES_DIR)/main-server.cpp \
			$(CORE_OBJECTS) \
			Domain/Factory/Factory.h \
			UI/UIFactoryInterface.h \
			UI/ServerTextUI/ServerTextUIInterface.h \
			| $(BUILD_DIR_SERVER) $(SRC_EXECUTABLES_DIR)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) \
		$(SRC_EXECUTABLES_DIR)/main-server.cpp -o $@


#	Console client executable object
$(BUILD_DIR_CLIENT)/Client_Console.o:	\
					$(SRC_EXECUTABLES_DIR)/main-console-client.cpp \
					$(CORE_OBJECTS) \
					| $(BUILD_DIR_CLIENT) $(SRC_EXECUTABLES_DIR)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) \
		$(SRC_EXECUTABLES_DIR)/main-console-client.cpp -o $@


#	Core :: Domain :: Server :: ServerFactory
$(BUILD_DIR_CORE)/Domain_Server_ServerFactory.o:	\
					Domain/Server/ServerFactory.h Domain/Server/ServerFactory.cpp \
					ForwardDeclarations.h \
					Domain/Server/ServerFactoryInterface.h \
					Domain/Server/ServerDaemon.h \
					Domain/Server/ServerDaemonInterface.h \
					Domain/Server/ServerUpdater.h \
					Domain/Server/ServerUpdaterInterface.h \
					Domain/Server/HACCS_REPORT.h \
					Domain/Server/HACCS_REPORT_INTERFACE.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Server/ServerFactory.cpp -o $@


#	Core :: Domain :: Server :: ServerDaemon
$(BUILD_DIR_CORE)/Domain_Server_ServerDaemon.o:	\
					Domain/Server/ServerDaemon.h Domain/Server/ServerDaemon.cpp \
					ForwardDeclarations.h \
					Domain/Factory/FactoryInterface.h \
					TechnicalServices/TechnicalServicesFactoryInterface.h \
					TechnicalServices/Persistence/DatabaserInterface.h \
					Domain/Server/ServerFactoryInterface.h \
					Domain/Server/ServerDaemonInterface.h \
					Domain/Server/ServerUpdater.h \
					Domain/Server/HACCS_REPORT.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Server/ServerDaemon.cpp -o $@


#	Core :: Domain :: Server :: ServerUpdater
$(BUILD_DIR_CORE)/Domain_Server_ServerUpdater.o:	\
					Domain/Server/ServerUpdater.h Domain/Server/ServerUpdater.cpp \
					ForwardDeclarations.h \
					Domain/Server/ServerUpdaterInterface.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Server/ServerUpdater.cpp -o $@


#	Core :: Domain :: Server :: HACCS_REPORT
$(BUILD_DIR_CORE)/Domain_Server_HACCS_REPORT.o:	\
					Domain/Server/HACCS_REPORT.h Domain/Server/HACCS_REPORT.cpp \
					ForwardDeclarations.h \
					Domain/Server/HACCS_REPORT_INTERFACE.h \
					Domain/Server/HACCS_REPORT_ACTIVITY_INTERFACE.h \
					Domain/Server/HACCS_REPORT_ACTIVITY.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Server/HACCS_REPORT.cpp -o $@


#	Core :: Domain :: Server :: HACCS_REPORT_ACTIVITY
$(BUILD_DIR_CORE)/Domain_Server_HACCS_REPORT_ACTIVITY.o:	\
					Domain/Server/HACCS_REPORT_ACTIVITY.h Domain/Server/HACCS_REPORT_ACTIVITY.cpp \
					ForwardDeclarations.h \
					Domain/Server/HACCS_REPORT_ACTIVITY_INTERFACE.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Server/HACCS_REPORT_ACTIVITY.cpp -o $@


#	Core :: Domain :: Game :: Actors :: Actor
$(BUILD_DIR_CORE)/Domain_Game_Actors_Actor.o:	\
					Domain/Game/Actors/Actor.h Domain/Game/Actors/Actor.cpp \
					ForwardDeclarations.h \
					Domain/Game/Defines.h \
					Domain/Game/Actors/ActorInterface.h \
					Domain/Game/Actors/Bullet.h \
					Domain/Game/Actors/Rect.h \
					Domain/Game/Actors/Vector.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Game/Actors/Actor.cpp -o $@


#	Core :: Domain :: Game :: Actors :: GunShip
$(BUILD_DIR_CORE)/Domain_Game_Actors_GunShip.o:	\
					Domain/Game/Actors/GunShip.h Domain/Game/Actors/GunShip.cpp \
					ForwardDeclarations.h \
					Domain/Game/Defines.h \
					Domain/Game/Actors/ActorInterface.h \
					Domain/Game/Actors/Vector.h \
					Domain/Game/Actors/Actor.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Game/Actors/GunShip.cpp -o $@


#	Core :: Domain :: Game :: Actors :: Bullet
$(BUILD_DIR_CORE)/Domain_Game_Actors_Bullet.o:	\
					Domain/Game/Actors/Bullet.h Domain/Game/Actors/Bullet.cpp \
					ForwardDeclarations.h \
					Domain/Game/Defines.h \
					Domain/Game/Actors/ActorInterface.h \
					Domain/Game/Actors/Vector.h \
					Domain/Game/Actors/Actor.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Game/Actors/Bullet.cpp -o $@


#	Core :: Domain :: Game :: Actors :: Rock
$(BUILD_DIR_CORE)/Domain_Game_Actors_Rock.o:	\
					Domain/Game/Actors/Rock.h Domain/Game/Actors/Rock.cpp \
					ForwardDeclarations.h \
					Domain/Game/Defines.h \
					Domain/Game/Actors/ActorInterface.h \
					Domain/Game/Actors/Actor.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Game/Actors/Rock.cpp -o $@


#	Core :: Domain :: Game :: Actors :: LongRock
$(BUILD_DIR_CORE)/Domain_Game_Actors_LongRock.o:	\
					Domain/Game/Actors/LongRock.h Domain/Game/Actors/LongRock.cpp \
					ForwardDeclarations.h \
					Domain/Game/Defines.h \
					Domain/Game/Actors/ActorInterface.h \
					Domain/Game/Actors/Actor.h \
					Domain/Game/Actors/Rock.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Game/Actors/LongRock.cpp -o $@


#	Core :: Domain :: Game :: Actors :: Rect
$(BUILD_DIR_CORE)/Domain_Game_Actors_Rect.o:	\
					Domain/Game/Actors/Rect.h Domain/Game/Actors/Rect.cpp \
					ForwardDeclarations.h \
					Domain/Game/Defines.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Game/Actors/Rect.cpp -o $@


#	Core :: Domain :: Game :: Actors :: Vector
$(BUILD_DIR_CORE)/Domain_Game_Actors_Vector.o:	\
					Domain/Game/Actors/Vector.h Domain/Game/Actors/Vector.cpp \
					ForwardDeclarations.h \
					Domain/Game/Defines.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Game/Actors/Vector.cpp -o $@


#	Core :: Domain :: Factory :: Factory
$(BUILD_DIR_CORE)/Domain_Factory_Factory.o:	\
					Domain/Factory/Factory.h Domain/Factory/Factory.cpp \
					ForwardDeclarations.h \
					Domain/Factory/FactoryInterface.h \
					Domain/Game/GameFactory.h \
					Domain/Game/GameFactoryInterface.h \
					Domain/Net/NetFactory.h \
					Domain/Net/NetFactoryInterface.h \
					Domain/Server/ServerFactory.h \
					Domain/Server/ServerFactoryInterface.h \
					Domain/Store/StoreFactory.h \
					Domain/Store/StoreFactoryInterface.h \
					TechnicalServices/TechnicalServicesFactory.h \
					TechnicalServices/TechnicalServicesFactoryInterface.h \
					UI/UIFactory.h \
					UI/UIFactoryInterface.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Factory/Factory.cpp -o $@


#	Core :: Domain :: Game :: GameFactory
$(BUILD_DIR_CORE)/Domain_Game_GameFactory.o:	\
					Domain/Game/GameFactory.h Domain/Game/GameFactory.cpp \
					ForwardDeclarations.h \
					Domain/Game/GameFactoryInterface.h \
					Domain/Game/Game.h \
					Domain/Game/Randomer.h \
					Domain/Game/GameHistory.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Game/GameFactory.cpp -o $@


#	Core :: Domain :: Game :: Randomer
$(BUILD_DIR_CORE)/Domain_Game_Randomer.o:	\
					Domain/Game/Randomer.h Domain/Game/Randomer.cpp \
					ForwardDeclarations.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Game/Randomer.cpp -o $@


#	Core :: Domain :: Game :: Game
$(BUILD_DIR_CORE)/Domain_Game_Game.o:	\
					Domain/Game/Game.h Domain/Game/Game.cpp \
					ForwardDeclarations.h \
					Domain/Factory/Factory.h \
					Domain/Factory/FactoryInterface.h \
					Domain/Game/Defines.h \
					Domain/Game/GameFactoryInterface.h \
					Domain/Game/Randomer.h \
					Domain/Game/GameInterface.h \
					Domain/Game/Actors/ActorInterface.h \
					Domain/Game/Actors/GunShip.h \
					Domain/Game/Actors/Bullet.h \
					Domain/Game/Actors/Rock.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Game/Game.cpp -o $@


#	Core :: Domain :: Game :: GameHistory
$(BUILD_DIR_CORE)/Domain_Game_GameHistory.o:	\
					Domain/Game/GameHistory.h Domain/Game/GameHistory.cpp \
					ForwardDeclarations.h \
					Domain/Game/GameHistoryInterface.h \
					Domain/Game/GAME_HISTORY_ENTRY_INTERFACE.h \
					Domain/Game/GAME_HISTORY_ENTRY.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Game/GameHistory.cpp -o $@


#	Core :: Domain :: Game :: GAME_HISTORY_ENTRY
$(BUILD_DIR_CORE)/Domain_Game_GAME_HISTORY_ENTRY.o:	\
					Domain/Game/GAME_HISTORY_ENTRY.h Domain/Game/GAME_HISTORY_ENTRY.cpp \
					ForwardDeclarations.h \
					Domain/Game/GAME_HISTORY_ENTRY.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Game/GAME_HISTORY_ENTRY.cpp -o $@


#	Core :: Domain :: Net :: Authentication :: Authenticator
$(BUILD_DIR_CORE)/Domain_Net_Authentication_Authenticator.o:	\
					Domain/Net/Authentication/Authenticator.h Domain/Net/Authentication/Authenticator.cpp \
					Domain/Net/Authentication/AuthenticationInterface.h \
					ForwardDeclarations.h \
					Domain/Net/Messages/AUTH_ATTEMPT.h \
					Domain/Net/Messages/AUTH_STATE.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Net/Authentication/Authenticator.cpp -o $@


#	Core :: Domain :: Net :: NetFactory
$(BUILD_DIR_CORE)/Domain_Net_Factory_NetFactory.o:	\
					Domain/Net/NetFactory.h Domain/Net/NetFactory.cpp \
					ForwardDeclarations.h \
					Domain/Net/NetFactoryInterface.h \
					Domain/Net/ClientServerCommunicator.h \
					Domain/Net/Authentication/Authenticator.h \
					Domain/Net/Authentication/AuthenticationInterface.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Net/NetFactory.cpp -o $@


#	Core :: Domain :: Net :: Messages :: AUTH_ATTEMPT
$(BUILD_DIR_CORE)/Domain_Net_Messages_AUTH_ATTEMPT.o:	\
					Domain/Net/Messages/AUTH_ATTEMPT.h Domain/Net/Messages/AUTH_ATTEMPT.cpp \
					ForwardDeclarations.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Net/Messages/AUTH_ATTEMPT.cpp -o $@


#	Core :: Domain :: Net :: ClientServerCommunicator
$(BUILD_DIR_CORE)/Domain_Net_ClientServerCommunicator.o:	\
					Domain/Net/ClientServerCommunicator.h Domain/Net/ClientServerCommunicator.cpp \
					ForwardDeclarations.h \
					Domain/Net/ClientServerCommunicatorInterface.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Net/ClientServerCommunicator.cpp -o $@


#	Core :: Domain :: Store :: StoreFactory
$(BUILD_DIR_CORE)/Domain_Store_StoreFactory.o:	\
					Domain/Store/StoreFactory.h Domain/Store/StoreFactory.cpp \
					ForwardDeclarations.h \
					Domain/Store/Enums/Enums.h \
					Domain/Store/StoreFactoryInterface.h \
					Domain/Store/StoreInterface.h \
					Domain/Store/Store.h \
					Domain/Store/PaymentHelper.h \
					Domain/Store/PaymentHelperInterface.h \
					Domain/Store/PAYMENT_RESULT_DETAILS.h \
					Domain/Store/PAYMENT_RESULT_DETAILS_INTERFACE.h \
					Domain/Store/POWERUP_ADDED_INFO_INTERFACE.h \
					Domain/Store/POWERUP_ADDED_INFO.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Store/StoreFactory.cpp -o $@


#	Core :: Domain :: Store :: Store
$(BUILD_DIR_CORE)/Domain_Store_Store.o:	\
					Domain/Store/Store.h Domain/Store/Store.cpp \
					ForwardDeclarations.h \
					Domain/Store/Enums/Enums.h \
					Domain/Store/StoreInterface.h \
					Domain/Store/STORE_ITEM.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Store/Store.cpp -o $@


#	Core :: Domain :: Store :: STORE_ITEM
$(BUILD_DIR_CORE)/Domain_Store_STORE_ITEM.o:	\
					Domain/Store/STORE_ITEM.h Domain/Store/STORE_ITEM.cpp \
					ForwardDeclarations.h \
					Domain/Store/Enums/Enums.h \
					Domain/Store/STORE_ITEM_INTERFACE.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Store/STORE_ITEM.cpp -o $@


#	Core :: Domain :: Store :: PaymentHelper
$(BUILD_DIR_CORE)/Domain_Store_PaymentHelper.o:	\
					Domain/Store/PaymentHelper.h Domain/Store/PaymentHelper.cpp \
					ForwardDeclarations.h \
					Domain/Factory/FactoryInterface.h \
					Domain/Net/NetFactoryInterface.h \
					Domain/Net/ClientServerCommunicatorInterface.h \
					Domain/Store/Enums/Enums.h \
					Domain/Store/PaymentHelperInterface.h \
					Domain/Store/PAYMENT_RESULT_DETAILS_INTERFACE.h \
					Domain/Store/PAYMENT_RESULT_DETAILS.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Store/PaymentHelper.cpp -o $@


#	Core :: Domain :: Store :: PAYMENT_RESULT_DETAILS
$(BUILD_DIR_CORE)/Domain_Store_PAYMENT_RESULT_DETAILS.o:	\
					Domain/Store/PAYMENT_RESULT_DETAILS.h Domain/Store/PAYMENT_RESULT_DETAILS.cpp \
					ForwardDeclarations.h \
					Domain/Store/Enums/Enums.h \
					Domain/Store/PAYMENT_RESULT_DETAILS_INTERFACE.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Store/PAYMENT_RESULT_DETAILS.cpp -o $@


#	Core :: Domain :: Store :: POWERUP_ADDED_INFO
$(BUILD_DIR_CORE)/Domain_Store_POWERUP_ADDED_INFO.o:	\
					Domain/Store/POWERUP_ADDED_INFO.h Domain/Store/POWERUP_ADDED_INFO.cpp \
					ForwardDeclarations.h \
					Domain/Store/Enums/Enums.h \
					Domain/Store/POWERUP_ADDED_INFO_INTERFACE.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Store/POWERUP_ADDED_INFO.cpp -o $@


#	Core :: TechnicalServices :: TechnicalServicesFactory
$(BUILD_DIR_CORE)/TechnicalServices_TechnicalServicesFactory.o:	\
					TechnicalServices/TechnicalServicesFactory.h TechnicalServices/TechnicalServicesFactory.cpp \
					ForwardDeclarations.h \
					TechnicalServices/TechnicalServicesFactoryInterface.h \
					TechnicalServices/Persistence/Databaser.h \
					TechnicalServices/Financial/CreditCardProcessorInterface.h \
					TechnicalServices/Financial/MastercardProcessor.h \
					TechnicalServices/Financial/VisaProcessor.h \
					TechnicalServices/Social/SocialMedia.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) TechnicalServices/TechnicalServicesFactory.cpp -o $@


#	Core :: TechnicalServices :: Persistence :: Databaser
$(BUILD_DIR_CORE)/TechnicalServices_Persistence_Databaser.o: \
					TechnicalServices/Persistence/Databaser.h TechnicalServices/Persistence/Databaser.cpp \
					ForwardDeclarations.h \
					TechnicalServices/Persistence/DatabaserInterface.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) TechnicalServices/Persistence/Databaser.cpp -o $@


#	Core :: TechnicalServices :: Financial :: FinancialServices
$(BUILD_DIR_CORE)/TechnicalServices_Financial_FinancialServices.o: \
					TechnicalServices/Financial/FinancialServices.h TechnicalServices/Financial/FinancialServices.cpp \
					ForwardDeclarations.h \
					TechnicalServices/Financial/FinancialServicesInterface.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) TechnicalServices/Financial/FinancialServices.cpp -o $@


#	Core :: TechnicalServices :: Financial :: MastercardProcessor
$(BUILD_DIR_CORE)/TechnicalServices_Financial_MastercardProcessor.o: \
					TechnicalServices/Financial/MastercardProcessor.h TechnicalServices/Financial/MastercardProcessor.cpp \
					ForwardDeclarations.h \
					TechnicalServices/Financial/CreditCardProcessorInterface.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) TechnicalServices/Financial/MastercardProcessor.cpp -o $@


#	Core :: TechnicalServices :: Financial :: VisaProcessor
$(BUILD_DIR_CORE)/TechnicalServices_Financial_VisaProcessor.o: \
					TechnicalServices/Financial/VisaProcessor.h TechnicalServices/Financial/VisaProcessor.cpp \
					ForwardDeclarations.h \
					TechnicalServices/Financial/CreditCardProcessorInterface.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) TechnicalServices/Financial/VisaProcessor.cpp -o $@


#	Core :: TechnicalServices :: Social :: SocialMedia
$(BUILD_DIR_CORE)/TechnicalServices_Social_SocialMedia.o: \
					TechnicalServices/Social/SocialMedia.h TechnicalServices/Social/SocialMedia.cpp \
					ForwardDeclarations.h \
					TechnicalServices/Social/SocialMediaInterface.h \
					TechnicalServices/Social/FRIEND_ON_SOCIAL_MEDIA.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) TechnicalServices/Social/SocialMedia.cpp -o $@


#	Core :: TechnicalServices :: Social :: FRIEND_ON_SOCIAL_MEDIA
$(BUILD_DIR_CORE)/TechnicalServices_Social_FRIEND_ON_SOCIAL_MEDIA.o: \
					TechnicalServices/Social/FRIEND_ON_SOCIAL_MEDIA.h TechnicalServices/Social/FRIEND_ON_SOCIAL_MEDIA.cpp \
					ForwardDeclarations.h \
					TechnicalServices/Social/FRIEND_ON_SOCIAL_MEDIA_INTERFACE.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) TechnicalServices/Social/FRIEND_ON_SOCIAL_MEDIA.cpp -o $@


#	Core :: UI :: UIFactory
$(BUILD_DIR_CORE)/UI_UIFactory.o:		\
					UI/UIFactory.h UI/UIFactory.cpp \
					ForwardDeclarations.h \
					UI/UIFactoryInterface.h \
					UI/ServerTextUI/ServerTextUIInterface.h \
					UI/ServerTextUI/ServerTextUI.h \
					UI/ClientTextUI/ClientTextUIInterface.h \
					UI/ClientTextUI/ClientTextUI.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) UI/UIFactory.cpp -o $@


#	Core :: UI :: ServerTextUI :: ServerTextUI
$(BUILD_DIR_CORE)/UI_ServerTextUI_ServerTextUI.o:	\
					UI/ServerTextUI/ServerTextUI.h UI/ServerTextUI/ServerTextUI.cpp \
					ForwardDeclarations.h \
					TechnicalServices/TechnicalServicesFactoryInterface.h \
					TechnicalServices/Financial/CreditCardProcessorInterface.h \
					Domain/Factory/FactoryInterface.h \
					Domain/Server/ServerFactoryInterface.h \
					Domain/Server/ServerDaemonInterface.h \
					Domain/Server/HACCS_REPORT_INTERFACE.h \
					Domain/Server/HACCS_REPORT_ACTIVITY_INTERFACE.h \
					UI/ServerTextUI/Enums/Enums.h \
					UI/ServerTextUI/ServerTextUIInterface.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) UI/ServerTextUI/ServerTextUI.cpp -o $@


#	Core :: UI :: ClientTextUI :: ClientTextUI
$(BUILD_DIR_CORE)/UI_ClientTextUI_ClientTextUI.o:	\
					UI/ClientTextUI/ClientTextUI.h UI/ClientTextUI/ClientTextUI.cpp \
					ForwardDeclarations.h \
					Domain/Factory/Factory.h \
					Domain/Factory/FactoryInterface.h \
					Domain/Game/GameFactoryInterface.h \
					Domain/Game/GameInterface.h \
					Domain/Game/Actors/ActorInterface.h \
					Domain/Game/GameHistory.h \
					Domain/Game/GAME_HISTORY_ENTRY_INTERFACE.h \
					Domain/Net/NetFactoryInterface.h \
					Domain/Net/ClientServerCommunicatorInterface.h \
					Domain/Net/Authentication/AuthenticationInterface.h \
					Domain/Net/Messages/AUTH_STATE.h \
					Domain/Store/Enums/Enums.h \
					Domain/Store/StoreFactoryInterface.h \
					Domain/Store/StoreInterface.h \
					Domain/Store/STORE_ITEM_INTERFACE.h \
					Domain/Store/PaymentHelperInterface.h \
					Domain/Store/PAYMENT_RESULT_DETAILS_INTERFACE.h \
					Domain/Store/POWERUP_ADDED_INFO_INTERFACE.h \
					Domain/Store/POWERUP_ADDED_INFO.h \
					UI/ClientTextUI/ClientTextUIInterface.h \
					UI/ClientTextUI/Defines.h \
					UI/ClientTextUI/Enums/Enums.h \
					UI/ClientTextUI/Input.h \
					UI/ClientTextUI/DisplayGrid.h \
					TechnicalServices/TechnicalServicesFactoryInterface.h \
					TechnicalServices/Social/SocialMediaInterface.h \
					TechnicalServices/Social/FRIEND_ON_SOCIAL_MEDIA_INTERFACE.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) UI/ClientTextUI/ClientTextUI.cpp -o $@


#	Core :: UI :: ClientTextUI :: DisplayGrid
$(BUILD_DIR_CORE)/UI_ClientTextUI_DisplayGrid.o:	\
					UI/ClientTextUI/DisplayGrid.h UI/ClientTextUI/DisplayGrid.cpp \
					ForwardDeclarations.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) UI/ClientTextUI/DisplayGrid.cpp -o $@


#	Core :: UI :: ClientTextUI :: Input
$(BUILD_DIR_CORE)/UI_ClientTextUI_Input.o:	\
					UI/ClientTextUI/Input.h UI/ClientTextUI/Input.cpp \
					ForwardDeclarations.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) UI/ClientTextUI/Input.cpp -o $@


#	Core :: Domain :: Net :: Messages :: AUTH_STATE
$(BUILD_DIR_CORE)/Domain_Net_Messages_AUTH_STATE.o:	\
					Domain/Net/Messages/AUTH_STATE.h Domain/Net/Messages/AUTH_STATE.cpp \
					ForwardDeclarations.h \
					| $(BUILD_DIR_CORE)
	$(info )
	$(call say,Building $@)
	$(CC) $(CFLAGS) Domain/Net/Messages/AUTH_STATE.cpp -o $@


#
exe: 			executables
executables:	$(SERVER_EXE_PATH) $(CLIENT_EXE_PATH)
	$(info )
	$(call say,Done building executables)
.PHONY: exe executables


#	Server executable
$(SERVER_EXE_PATH):	\
			$(BUILD_DIR_SERVER)/Server.o \
			| $(BIN_DIR)
	$(info )
	$(call say,Linking server executable)
	$(CC) $(BUILD_DIR_CORE)/*.o $(BUILD_DIR_SERVER)/Server.o \
		$(LINK_FLAGS) -o $@


#	Client executable
$(CLIENT_EXE_PATH):	\
			$(BUILD_DIR_CLIENT)/Client_Console.o \
			| $(BIN_DIR)
	$(info )
	$(call say,Linking console client executable)
	$(CC) $(BUILD_DIR_CORE)/*.o $(BUILD_DIR_CLIENT)/Client_Console.o \
		$(LINK_FLAGS) -o $@


#	Copy gdb source file for tracing through the "Play a Game" software sequence diagram
$(GDB_TRACE_PLAY_GAME_COMMANDS_DEST):	\
										$(GDB_TRACE_PLAY_GAME_COMMANDS_SRC) \
										| $(BIN_DIR)
	cp $(GDB_TRACE_PLAY_GAME_COMMANDS_SRC) $(GDB_TRACE_PLAY_GAME_COMMANDS_DEST)


#
build-server:	build-server-say
build-server:	$(SERVER_EXE_PATH) | $(BIN_DIR)
build-server-say:
	$(info )
	$(call say,Building server)
.PHONY:	build-server build-server-say


#
run-server:		build-server
	$(call say,Running server)
	cd $(BIN_DIR) && ./$(SERVER_EXE_NAME)
.PHONY: run-server


#
debug-server:	debug-server-say
debug-server:	build-server
	cd $(BIN_DIR) && gdb -ex=run --args $(SERVER_EXE_PATH)
debug-server-say:
	$(info )
	$(call say,Debugging server ...)
.PHONY:	debug-server debug-server-say


#
build-console-client:	build-console-client-say
build-console-client:	$(CLIENT_EXE_PATH) | $(BIN_DIR)
build-console-client-say:
	$(info )
	$(call say,Building console client)
.PHONY:	build-console-client build-console-client-say


#	Run the console client
run-console-client:	run-console-client-say
run-console-client:	build-console-client
	cd $(BIN_DIR) && ./$(CLIENT_EXE_PATH)
run-console-client-say:
	$(info )
	$(call say,Running console client)
.PHONY: run-console-client run-console-client-say

#	Debug the console client
debug-console-client:	debug-console-client-say
debug-console-client:	build-console-client
	cd $(BIN_DIR) && gdb -ex=run --args $(CLIENT_EXE_PATH)
debug-console-client-say:
	$(info )
	$(call say,Debugging the console client)
.PHONY: run-console-client run-console-client-say


#	Run a trace through the software sequence diagram for "Play a Game"
trace-play-game:	trace-play-game-say
trace-play-game:	build-console-client $(GDB_TRACE_PLAY_GAME_COMMANDS_DEST)
	cd $(BIN_DIR) && cgdb -x $(GDB_TRACE_PLAY_GAME_COMMANDS_FILENAME)
trace-play-game-say:
	$(info )
	$(call say,Debug stepping through software sequence diagram for "Play a Game")
.PHONY:	trace-play-game


#
docs:	docs-build docs-deploy
.PHONY: docs


#
docs-build:	docs-build-say
docs-build:	| $(DOCS_DIR)
	doxygen Doxyfile
docs-build-say:
	$(call say,Building documentation)
.PHONY: docs-build docs-build-say


#
docs-deploy:	docs-deploy-say
docs-deploy:	docs
	$(call say,Deploying docs)
	rsync --archive --stats --itemize-changes --human-readable --delete $(DOCS_DEPLOY_LOCAL_PATH) $(DOCS_DEPLOY_USERNAME)@$(DOCS_DEPLOY_HOSTNAME):$(DOCS_DEPLOY_REMOTE_PATH)
docs-deploy-say:
	$(call say,Deploying docs)
.PHONY:	docs-deploy



#
clean:	clean-say
	-rm -rfv $(BUILD_DIR_CORE)/*.o
	-rm -rfv $(BUILD_DIR_SERVER)/*.o
	-rm -rfv $(BUILD_DIR_CLIENT)/*.o
	-rm -v $(SERVER_EXE_PATH)
	-rm -v $(CLIENT_EXE_PATH)
clean-say:
	$(call say,Cleaning ...)
.PHONY: clean clean-say


