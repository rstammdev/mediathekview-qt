/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "channels.h"

using namespace Qt::Literals::StringLiterals;


const QList<QStringList> Channels::channels()
{
    // Channel: [0] Id, [1] Name, [2] Short Name, [3] Long Name, [4] Brief Description

    return QList<QStringList> {
        { "channel_3sat"_L1, tr("3sat"), tr("3sat"), tr("3sat"), tr("German-language european television channel dedicated to culture") },
        { "channel_ard"_L1, tr("Das Erste"), tr("ARD"), tr("Erstes Deutsches Fernsehen"), tr("German-language national German television channel") },
        { "channel_ard_alpha"_L1, tr("ARD alpha"), tr("alpha"), tr("ARD alpha"), tr("German-language German television channel dedicated to education") },
        { "channel_arte_de"_L1, tr("ARTE.DE"), tr("ARTE.DE"), tr("ARTE.DE"), tr("German-language European television channel dedicated to culture") },
        { "channel_arte_en"_L1, tr("ARTE.EN"), tr("ARTE.EN"), tr("ARTE.EN"), tr("English-language European television channel dedicated to culture") },
        { "channel_arte_es"_L1, tr("ARTE.ES"), tr("ARTE.ES"), tr("ARTE.ES"), tr("Spanish-language European television channel dedicated to culture") },
        { "channel_arte_fr"_L1, tr("ARTE.FR"), tr("ARTE.FR"), tr("ARTE.FR"), tr("French-language European television channel dedicated to culture") },
        { "channel_arte_it"_L1, tr("ARTE.IT"), tr("ARTE.IT"), tr("ARTE.IT"), tr("Italian-language European television channel dedicated to culture") },
        { "channel_arte_pl"_L1, tr("ARTE.PL"), tr("ARTE.PL"), tr("ARTE.PL"), tr("Polish-language European television channel dedicated to culture") },
        { "channel_br"_L1, tr("BR"), tr("BR"), tr("Bayerischer Rundfunk"), tr("German-language regional German television channel serving Bavaria") },
        { "channel_dw"_L1, tr("DW-TV"), tr("DW"), tr("Deutsche Welle TV"), tr("Multi-language German television channel serving world-wide") },
        { "channel_funk"_L1, tr("funk"), tr("funk"), tr("funk"), tr("German-language German online television channel") },
        { "channel_hr"_L1, tr("HR"), tr("HR"), tr("Hessischer Rundfunk"), tr("German-language regional German television channel serving Hesse") },
        { "channel_kika"_L1, tr("KiKA"), tr("KiKA"), tr("Der Kinderkanal"), tr("German-language German television channel dedicated to children and the youth") },
        { "channel_mdr"_L1, tr("MDR"), tr("MDR"), tr("Mitteldeutscher Rundfunk"), tr("German-language regional German television channel serving Thuringia, Saxony and Saxony-Anhalt") },
        { "channel_ndr"_L1, tr("NDR"), tr("NDR"), tr("Norddeutscher Rundfunk"), tr("German-language regional German television channel serving Hamburg, Lower Saxony, Mecklenburg-Vorpommern and Schleswig-Holstein") },
        { "channel_one"_L1, tr("one"), tr("one"), tr("one"), tr("German-language German television channel dedicated to entertainment") },
        { "channel_orf"_L1, tr("ORF"), tr("ORF"), tr("Österreichischer Rundfunk"), tr("German-language national Austrian television channel") },
        { "channel_phoenix"_L1, tr("phoenix"), tr("phoenix"), tr("phoenix"), tr("German-language German television channel dedicated to news and documentary") },
        { "channel_rb"_L1, tr("RB-TV"), tr("RB"), tr("Radio Bremen TV"), tr("German-language regional German television channel serving Bremen") },
        { "channel_rbb"_L1, tr("RBB"), tr("RBB"), tr("Rundfunk Berlin-Brandenburg"), tr("German-language regional German television channel serving Berlin and Brandenburg") },
        { "channel_sr"_L1, tr("SR"), tr("SR"), tr("Saarländischer Rundfunk"), tr("German-language regional German television channel serving Saarland") },
        { "channel_srf"_L1, tr("SRF"), tr("SRF"), tr("Schweizer Radio und Fernsehen"), tr("German-language national Swiss television channel") },
        { "channel_swr"_L1, tr("SWR"), tr("SWR"), tr("Südwestrundfunk"), tr("German-language regional German television channel serving Baden-Württemberg and Rhineland-Palatinate") },
        { "channel_tagesschau24"_L1, tr("tagesschau24"), tr("tagesschau24"), tr("tagesschau24"), tr("German-language German television channel dedicated to news") },
        { "channel_wdr"_L1, tr("WDR"), tr("WDR"), tr("Westdeutscher Rundfunk"), tr("German-language regional German television channel serving North Rhine-Westphalia") },
        { "channel_zdf"_L1, tr("ZDF"), tr("ZDF"), tr("Zweites Deutsches Fernsehen"), tr("German-language national German television channel") },
        { "channel_zdf_info"_L1, tr("ZDFinfo"), tr("info"), tr("ZDFinfo"), tr("German-language German television channel dedicated to news") },
        { "channel_zdf_neo"_L1, tr("ZDFneo"), tr("neo"), tr("ZDFneo"), tr("German-language German television channel dedicated to an audience aged 25 to 49") },
        { "channel_zdf_tivi"_L1, tr("ZDFtivi"), tr("tivi"), tr("ZDFtivi"), tr("German-language German television channel dedicated to children and the youth") },
    };
}
