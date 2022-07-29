/**********************************************************************
*                 SEGGER Software GmbH                               *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2019  SEGGER Microcontroller GmbH                *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.48 - Graphical user interface for embedded applications **
All  Intellectual Property rights in the Software belongs to  SEGGER.
emWin is protected by  international copyright laws.  Knowledge of the
source code may not be used to write a similar product. This file may
only be used in accordance with the following terms:

The  software has  been licensed by SEGGER Software GmbH to Realtek 
Semiconductor Corp. at the address: Realtek Semiconductor Corp., 
Hsinchu Science Park, Innovation Rd. II 2, 300 Hsinchu city, Taiwan for 
the purposes  of  creating  libraries  for its Cortex-M series of 
Microcontroller Units designed, branded, marketed and manufactured by 
Realtek Semiconductor Corp. under the terms and conditions of an End 
User License Agreement supplied with the libraries.

Full source code is available at: www.segger.com

We appreciate your understanding and fairness.
----------------------------------------------------------------------
Licensing information
Licensor:                 SEGGER Software GmbH
Licensed to:              Realtek Semiconductor Corp., Hsinchu Science Park, Innovation Rd. II 2, 300 Hsinchu city, Taiwan
Licensed SEGGER software: emWin
License number:           GUI-00784
License model:            emWin Buyout Agreement, signed May 15th, 2019
Licensed platform:        Cortex-M series of Microcontroller Units designed, branded, marketed and manufactured by LICENSEE
----------------------------------------------------------------------
File        : WINDOW_Private.h
Purpose     : WINDOW private header file
--------------------END-OF-HEADER-------------------------------------
*/

#ifndef WINDOW_PRIVATE_H
#define WINDOW_PRIVATE_H

#include "WM.h"

#if GUI_WINSUPPORT

/*********************************************************************
*
*       Object definition
*
**********************************************************************
*/

typedef struct {
  WIDGET Widget;
  WM_CALLBACK * cb;
  WM_HWIN hFocusedChild;
  WM_DIALOG_STATUS * pDialogStatus;
  GUI_COLOR BkColor;
} WINDOW_OBJ;

/*********************************************************************
*
*       Externals
*
**********************************************************************
*/

extern GUI_COLOR WINDOW__DefaultBkColor;

#endif   /* GUI_WINSUPPORT */
#endif   /* WINDOW_PRIVATE_H */

/*************************** End of file ****************************/
