# submissions
Gather information from all submissions to a Mooshak contest.

Call with:

`submissions <contest path> <operation> [<filter path>]`

## 1st argument is the contest folder path, eg:
 
 `/home/mooshak/data/contests/aContestFolder`
 
#### 2nd argument is the operation, and can be:
``` 
All               list all submissions
Accepted          list only "Accepted" submissions
AcceptedFinal     list only "Accepted" and "final" submissions
Fail              list failed submissions
FailType          list failed submissions grouped by type
AcceptedFailType  list failed submissions grouped by type, only if team as one "Accepted" submission to the problem
                  (used to get info from Mooshak to assessment sheets)
mapAll            map counter of all submissions classification for each problem
mapFinal          map counter of all submissions classification for each problem, marked as "final"
```

For operations: "All", "Accepted" and "AcceptedFinal", list is formatted as sample below and sorted alphabetically.
Columns from left to right are:

- Mooshak contest's problem name
- Team name
- Submission state
- Submission marked as **final** or **pending** review

 ``` 
 A,12335,Accepted,final
 A,23456,Accepted,pending
 A,23456,Wrong Answer,pending
 B,13456,Accepted,pending
 (...)
 ``` 
 For operation "Fail" list is formatted as sample below and sorted alphabetically:
 ``` 
 A,44340,Runtime Error,1
 A,44340,Wrong Answer,2
 A,49551,Wrong Answer,1
 A,52080,Runtime Error,1
 A,52770,Wrong Answer,1
 (...)
 ``` 
 For operation "FailType" and "AcceptedFailType", list is formatted as sample below and sorted alphabetically:
 ``` 
 A,44340,3
 A,49551,1
 A,52080,1
 A,52770,1
 (...)
 ``` 
 For operation "mapAll" and "mapFinal", map is formatted as sample below:
 ``` 
 nofail  *    *              *              *    *
 Prob  Acc CTEr Eval InFn InSb MLEx OLEx PErr PSEx REvl RTEr TLEx WrAn Total Fails
   A    89   35    0    0    0    0    0    2    0    0   41    0   34   201    75
   B   115   19    0    0    0    0    0    4    0    0   55    0   46   239   101
   C   139   29    0    0    0    0    0    9    1    0   37    0   57   272    94
   D   120   24    0    0    0    0    0    0    0    0   18    0  115   277   133
   E    83   87    0    0    0    0    0    0    0    0   13    0   11   194    24
   F   119   38    0    0    0    0    0    2    0    0   27    0   26   212    53
   G    74   22    0    0    0    0    0    3    0    0    5    0   13   117    18
   H    47   38    0    0    0    0    0   13    1    0    4    0   16   119    20
 ``` 
 Classifications listed below are the only ones not considered as failure:
 *	(This is harded coded in current version)
 *		Accepted
 *		Compile Time Error
 *		Invalid Submission
 *		Presentation Error
 *		Program Size Exceeded
 *
 */




# 3rd argument is an optional path to a Team filter for name fixing
 *
 *
 
