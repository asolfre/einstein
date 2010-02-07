// ==============================
// Fichier:			TTraceMonitor.h
// Projet:			K
//
// Cr�� le:			05/09/2002
// Tabulation:		4 espaces
//
// ***** BEGIN LICENSE BLOCK *****
// Version: MPL 1.1
//
// The contents of this file are subject to the Mozilla Public License Version
// 1.1 (the "License"); you may not use this file except in compliance with
// the License. You may obtain a copy of the License at
// http://www.mozilla.org/MPL/
//
// Software distributed under the License is distributed on an "AS IS" basis,
// WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
// for the specific language governing rights and limitations under the
// License.
//
// The Original Code is TTraceMonitor.h.
//
// The Initial Developer of the Original Code is Paul Guyot.
// Portions created by the Initial Developer are Copyright (C) 2002-2004
// the Initial Developer. All Rights Reserved.
//
// Contributor(s):
//   Paul Guyot <pguyot@kallisys.net> (original author)
//
// ***** END LICENSE BLOCK *****
// ===========

#ifndef __TTRACEMONITOR__
#define __TTRACEMONITOR__

#include <K/Defines/KDefinitions.h>
#include <K/Tests/TFunctionMonitor.h>

///
/// Classe pour afficher la trace.
///
/// \author Paul Guyot <pguyot@kallisys.net>
/// \version 1.0
///
/// \test	aucun test d�fini.
///
class TTraceMonitor : public TFunctionMonitor
{
public:
	///
	/// Modes
	///
	enum EMode {
		kNone			=	0,
		kDisplayBegin	=	1 << 0,
		kDisplayEnd		=	1 << 1,
		kKeepStack		=	1 << 2
	};

	///
	/// Constructeur � partir d'un entier repr�sentant le mode.
	///
	/// \param	inMode	mode � utiliser. Les bits sont d�finis dans EMode.
	///
	TTraceMonitor( unsigned int inMode );
	
	///
	/// Destructeur.
	///
	virtual ~TTraceMonitor( void );

	///
	/// D�but d'une fonction.
	/// Cette m�thode est appel�e par le constructeur de TMethodMonitor.
	/// inFileName n'est pas copi�.
	/// Elle va appeler DoPrintBegin si le mode comprend
	/// \c kDisplayBegin.
	///
	/// \param inFileName		nom du fichier. A priori, ce pointeur
	///							reste le m�me entre les appels.
	/// \param inLineNumber		num�ro de la ligne.
	///
	virtual void FunctionBegin(
						const char* inFileName,
						unsigned int inLineNumber );

	///
	/// Fin d'une fonction.
	/// Cette m�thode est appel�e par le destructeur de TMethodMonitor.
	/// Elle va appeler DoPrintEnd si le mode comprend \c kDisplayEnd.
	///
	/// \param inFileName		nom du fichier. A priori, ce pointeur
	///							reste le m�me entre les appels.
	/// \param inLineNumber		num�ro de la ligne.
	///
	virtual void FunctionEnd(
						const char* inFileName,
						unsigned int inLineNumber );

	///
	/// S�lecteur sur le mode.
	/// (d�termine ce qu'on affiche)
	///
	/// \param	inMode	mode � utiliser (les bits sont d�finis par EMode)
	///
	void SetMode( unsigned int inMode );
	
	///
	/// Affiche la pile.
	/// Cette m�thode va appeler DoPrintStack pour chaque appel dans
	/// la pile si le mode comprend \c kKeepStack.
	///
	void PrintStack( void );
	
protected:
	///
	/// Affiche une ligne pour le d�but d'une fonction.
	/// La m�thode par d�faut utilise ::printf.
	///
	/// \param	inStackDepth	profondeur courante de la pile.
	///							(vaut 0 si on ne garde pas trace de la pile)
	/// \param	inFileName		nom du fichier
	/// \param	inLineNumber	num�ro de ligne
	///
	virtual void DoPrintBegin(
						unsigned int inStackDepth,
						const char* inFileName,
						unsigned int inLineNumber );

	///
	/// Affiche une ligne pour la fin d'une fonction.
	/// La m�thode par d�faut utilise ::printf.
	///
	/// \param	inStackDepth	profondeur courante de la pile.
	///							(vaut 0 si on ne garde pas trace de la pile)
	/// \param	inFileName		nom du fichier
	/// \param	inLineNumber	num�ro de ligne
	///
	virtual void DoPrintEnd(
						unsigned int inStackDepth,
						const char* inFileName,
						unsigned int inLineNumber );
	///
	/// Affiche une ligne pour la pile.
	/// La m�thode par d�faut utilise ::printf.
	///
	/// \param	inFileName		nom du fichier
	/// \param	inLineNumber	num�ro de ligne
	///
	virtual void DoPrintStack(
						const char* inFileName,
						unsigned int inLineNumber );
private:
	///
	/// Structure pour la pile.
	/// Comprend le nom du fichier et le num�ro de ligne.
	///
	struct SStackEntry {
		const char*		fFileName;		///< Nom du fichier
		unsigned int	fLineNumber;	///< Num�ro de ligne
	};
	
	enum {
		kStackSizeIncrement	= 10		///< Incr�ment � chaque fois
										///< que la pile est pleine.
	};
	
	unsigned int		mMode;			///< Mode (cf \c EMode)
	unsigned int		mStackDepth;	///< Profondeur de la pile
	unsigned int		mStackCapacity;	///< Capacit� de la pile
	SStackEntry*		mStack;			///< Pile
};

#endif
		// __TTRACEMONITOR__

// ============================================ //
// Our OS who art in CPU, UNIX be thy name.     //
//         Thy programs run, thy syscalls done, //
//         In kernel as it is in user!          //
// ============================================ //