// ==============================
// File:			TAndroidApp.h
// Project:			Einstein
//
// Copyright 2011 by Matthias Melcher (einstein@matthiasm.com).
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
// ==============================
// $Id$
// ==============================

#ifndef _TANDROIDAPP_H
#define _TANDROIDAPP_H

#include <K/Defines/KDefinitions.h>

#include "AndroidGlue.h"
#include "Version.h"

class TROMImage;
class TEmulator;
class TSoundManager;
class TScreenManager;
class TLog;
class TPlatformManager;

///
/// Classe pour le programme einstein en ligne de commande.
///
/// \author Paul Guyot <pguyot@kallisys.net>
/// \author Matthias Melcher <einstein@matthiasm.com>
/// \version $Revision: 113 $
///
/// \test	aucun test d�fini.
///
class TAndroidApp
{
public:
	///
	/// Constructeur par d�faut.
	///
	TAndroidApp( void );
	
	///
	/// Destructeur.
	///
	~TAndroidApp( void );
	
	///
	/// Point d'entr�e.
	///
	void Run();
	
	///
	/// user requested simulating the power button
	///
	void menuPower();
	
	///
	/// user requested simulating holding the power button longer
	///
	void menuBacklight();
	
	///
	/// user requested to install a package
	///
	void menuInstallPackage();
	
	///
	/// show the "About..." screen
	///
	void menuAbout();
	
	///
	/// user wants to see the Settings dialog box
	///
	void menuShowSettings();
	
	///
	/// Open the dialog to download the ROM via TCP/IP 
	///
	void menuDownloadROM();
	
	TPlatformManager *getPlatformManager() { return mPlatformManager; }
private:
	///
	/// Constructeur par copie volontairement indisponible.
	///
	/// \param inCopy		objet � copier
	///
	TAndroidApp( const TAndroidApp& inCopy );
	
	///
	/// Op�rateur d'assignation volontairement indisponible.
	///
	/// \param inCopy		objet � copier
	///
	TAndroidApp& operator = ( const TAndroidApp& inCopy );
	
	///
	/// Affiche un message d'erreur sur la syntaxe et sort.
	///
	void SyntaxError( void );
	
	///
	/// Affiche un message d'erreur sur la syntaxe (une option en particulier)
	/// et sort.
	///
	/// \param inBadOption	bad option
	///
	void SyntaxError( const char* inBadOption );
	
	///
	/// Affiche l'aide et sort.
	///
	void Help( void );
	
	///
	/// Affiche la version et sort.
	///
	void Version( void );
	
	///
	/// Cr�e le gestionnaire de son.
	///
	void CreateSoundManager( const char* inClass );
	
	///
	/// Cr�e le gestionnaire d'�cran.
	///
	void CreateScreenManager(
							 const char* inClass,
							 int inPortraitWidth,
							 int inPortraitHeight,
							 Boolean inFullScreen);
	
	///
	/// Cr�e le log.
	///
	void CreateLog( const char* inPath );
	
	///
	/// Point d'entr�e du processus l�ger.
	///
	static void* SThreadEntry( void* inUserData )
	{
		((TAndroidApp*) inUserData)->ThreadEntry();
		return NULL;
	}
	
	///
	/// Point d'entr�e du processus l�ger.
	///
	void ThreadEntry( void );
	
	///
	/// Boucle du menu.
	///
	void MenuLoop( void );
	
	///
	/// Boucle du menu (moniteur)
	///
	void MonitorMenuLoop( void );
	
	///
	/// Boucle du menu (app)
	///
	void AppMenuLoop( void );
	
	///
	/// Execute a command.
	///
	/// \return true if the command was known.
	///
	Boolean ExecuteCommand( const char* inCommand );
	
	///
	/// Affiche l'aide (du menu)
	///
	void PrintHelp( void );
	
	///
	/// Affiche une ligne (dans stdout ou via le moniteur)
	///
	void PrintLine( const char* inLine );
	
	/// \name Variables
	const char*			mProgramName;		///< Nom du programme.
	TROMImage*			mROMImage;			///< Image ROM.
	TEmulator*			mEmulator;			///< Emulateur.
	TSoundManager*		mSoundManager;		///< Gestionnaire de son.
	TScreenManager*		mScreenManager;		///< Gestionnaire d'�cran.
	TPlatformManager*	mPlatformManager;	///< Reference to the platform manager.
	TLog*				mLog;				///< Log.
	Boolean				mQuit;				///< If we should quit.
};

#endif
// _TANDROIDAPP_H

// ============================================================================ //
// Mac Airways:                                                                 //
// The cashiers, flight attendants and pilots all look the same, feel the same  //
// and act the same. When asked questions about the flight, they reply that you //
// don't want to know, don't need to know and would you please return to your   //
// seat and watch the movie.                                                    //
// ============================================================================ //
