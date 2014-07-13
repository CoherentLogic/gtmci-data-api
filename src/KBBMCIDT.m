KBBMCIDT ;CLD/JPW - GT.M CALLIN DATA ACCESS API;7/13/2014
;;0.01;CIDT;**PATCHES**;7/13/2014;Build 0
;;
;; Copyright (C) 2014 Coherent Logic Development LLC
;;  All Rights Reserved
;;
;; Author:  John P. Willis <jpw@coherent-logic.com>
;; Written: 7/12/2014
;;
;;  This file is part of gtmci-data-api.
;;
;;  gtmci-data-api is free software: you can redistribute it and/or modify
;;  it under the terms of the GNU Affero General Public License as published by
;;  the Free Software Foundation, either version 3 of the License, or
;;  (at your option) any later version.
;;
;;  gtmci-data-api is distributed in the hope that it will be useful,
;;  but WITHOUT ANY WARRANTY; without even the implied warranty of
;;  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;;  GNU General Public License for more details.
;;
;;  You should have received a copy of the GNU Affero General Public License
;;  along with gtmci-data-api.  If not, see <http://www.gnu.org/licenses/>. 
;;
 QUIT ""
 ;
SET(GLVN,VALUE)
 S @GLVN=VALUE
 QUIT 1
 ;
 ;
GET(GLVN)
 QUIT @GLVN
 ;
 ;
KILL(GLVN)
 K @GLVN
 QUIT 1
 ;
 ;
DATA(GLVN)
 QUIT $D(@GLVN)
 ;
 ;
ORDER(GLVN)
 QUIT $O(@GLVN)
 ;
 ;
QUERY(GLVN)
 QUIT $Q(@GLVN)
 ;
 ;
LOCK(GLVN)
 L +@GLVN
 QUIT $T
 ;
 ;
UNLOCK(GLVN)
 L -@GLVN
 QUIT $T
 ;
 ;
VERSION()
 QUIT $ZVERSION
 ;
 ;
FUNCTION(FN)
 N RESULT S RESULT=""
 X "S RESULT=$$"_FN
 QUIT RESULT
 ;
 ;