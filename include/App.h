/////////////////////////////////////////////////////////////////////////////
// Name:        App.h
// Purpose:     An application object
// Author:      Dave Page
// Created:     2007-02-13
// RCS-ID:      $Id: App.h,v 1.2 2007/02/20 12:20:24 dpage Exp $
// Copyright:   (c) EnterpriseDB
// Licence:     BSD Licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _APP_H
#define _APP_H

#include "StackBuilder.h"

// wxWindows headers
#include <wx/wx.h>
#include <wx/treectrl.h>

class AppList;

class App : public wxTreeItemData
{
public:
	App(AppList *applist);
	bool IsValid();
	bool IsInstalled();
	bool IsVersionInstalled();
    bool WorksWithDB(ServerData *server);
	wxString GetInstalledVersion();
	void SelectForDownload(bool select, bool isdep);
	bool IsSelectedForDownload() { return download; };
	bool IsSelectedAsDependency() { return isDependency; };
	int RankDependencies(int rank);

	wxString id;
	wxString name;
	wxString description;
	wxString version;
	wxString category;
	wxString dbversion;
	wxString format;
	wxString installoptions;
	wxString upgradeoptions;
	wxString checksum;
	wxString mirrorpath;
	wxArrayString dependencies;

	wxTreeItemId m_treeitem;
	wxTreeCtrl *m_tree;

	int sequence;

private:
	bool download, isDependency;
	AppList *m_applist;
};

#endif