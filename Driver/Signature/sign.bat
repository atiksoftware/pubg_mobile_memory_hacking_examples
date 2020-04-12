makecert -r -pe -n "CN=Amiral CA" -ss CA -sr CurrentUser -a sha256 -cy authority -sky signature -sv AmiralCA.pvk AmiralCA.cer
certutil -user -addstore Root AmiralCA.cer
makecert -pe -n "CN=Amiral Router" -a sha256 -cy end -sky signature -ic AmiralCA.cer -iv AmiralCA.pvk -sv AmiralSPC.pvk AmiralSPC.cer
pvk2pfx -pvk AmiralSPC.pvk -spc AmiralSPC.cer -pfx AmiralSPC.pfx
signtool sign /v /f AmiralSPC.pfx /t http://timestamp.verisign.com/scripts/timstamp.dll amiralrouterdvr.sys