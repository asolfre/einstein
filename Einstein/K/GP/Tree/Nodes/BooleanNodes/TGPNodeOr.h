// ==============================
// Fichier:			TGPNodeOr.h
// Projet:			K
//
// Cr�� le:			25/2/2003
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
// The Original Code is TGPNodeOr.h.
//
// The Initial Developer of the Original Code is Paul Guyot.
// Portions created by the Initial Developer are Copyright (C) 2003-2004
// the Initial Developer. All Rights Reserved.
//
// Contributor(s):
//   Paul Guyot <pguyot@kallisys.net> (original author)
//
// ***** END LICENSE BLOCK *****
// ===========
// $Id: TGPNodeOr.h,v 1.7 2004/11/23 15:11:31 paul Exp $
// ===========

#ifndef _TGPNODEOR_H
#define _TGPNODEOR_H

#include <K/Defines/KDefinitions.h>
#include <K/GP/Tree/Nodes/BooleanNodes/TGPNodeBoolean.h>

// ISO C++
#include <string>

///
/// Classe pour une disjonction de sous-noeuds.
///
/// \author Paul Guyot <pguyot@kallisys.net>
/// \version 1.0
///
/// \test	aucun test d�fini.
///
class TGPNodeOr
	:
		public TGPNodeBoolean
{
public:
	///
	/// Constructeur � partir de l'arit�.
	///
	/// \param	inArity		arit� du noeud.
	///
	TGPNodeOr( KUInt32 inArity );

	///
	/// R�cup�re le nom du noeud.
	/// Ce nom doit �tre unique et permettre de recr�er le noeud (sans
	/// les sous-noeuds).
	///
	/// \return	une r�f�rence sur la cha�ne qui identifie le noeud.
	///
	virtual TStringRef		GetLispName( void ) const;

private:
	///
	/// �valuation.
	///
	/// Cette m�thode est appel�e plusieurs fois par l'interpr�teur.
	/// Elle retourne un sous-noeud � �valuer pour l'interpr�teur, afin de
	/// calculer son propre r�sultat, ou \c nil lorsque l'�valuation est termin�e.
	/// Dans ce cas, le r�sultat doit �tre renseign� dans \c ioResult.
	///
	/// \param inNodeRef	r�f�rence sur le noeud �valu�.
	/// \param ioResult		en entr�e, r�sultat de l'�valuation du sous-noeud
	///						demand�.
	///						en sortie, r�sultat de l'�valuation de ce noeud.
	/// \param ioStorage	entrep�t pour des donn�es (laiss� � la discr�tion
	///						du noeud)
	/// \param inContext	contexte pour l'�valuation.
	/// \param ioCookie		biscuit (mis � z�ro par l'interpr�teur au d�but de
	///						l'�valuation de ce noeud).	
	/// \return un sous-noeud dont la m�thode veut le r�sultat, \c nil
	///			lorsque l'�valuation est termin�e.
	///
	virtual TGPNodeRef*	Evaluate(
							TGPNodeRef* inNodeRef,
							TGPDataRef* ioResult,
							std::vector<TGPDataRef>& ioStorage,
							TGPEvaluationContext* inContext,
							KUIntPtr* ioCookie );

	/// \name Constantes
	static const char*	kLispFormat;	///< Format du nom du noeud.
	
	/// \name Variables
	TStringRef			mLispName;		///< Nom du noeud.
};

#endif
		// _TGPNODEOR_H

// =========================== //
// Kiss your keyboard goodbye! //
// =========================== //
