BOOL SaveResource(int ResID, LPTSTR lpPathName)
{
	BOOL bRtn=1;
	LPTSTR lpRes;
	HRSRC hResInfo;
	HANDLE hRes;
	DWORD dwSize;

	hResInfo=FindResourceW(g_hInst, MAKEINTRESOURCE(ResID), L"JAR");

	if(hResInfo==NULL)
		return FALSE;

	// Load the wave resource. 
	hRes=LoadResource(g_hInst, hResInfo);

	if(hRes==NULL)
		return FALSE;

	// Get size of resource.
	dwSize=SizeofResource(g_hInst, hResInfo);

	// Lock the wave resource and play it. 
	lpRes=(LPTSTR) LockResource(hRes);


	if(lpRes!=NULL)
	{ // 실제 파일로 저장하는 부분
		FILE *fp=_wfopen(lpPathName, L"wb+");
		fwrite(lpRes, dwSize, 1, fp);
		fclose(fp);
	}
	else
		bRtn=0;

	return bRtn;
}
