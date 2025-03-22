#include "printer.h"


void printTextFile(HDC hdc, const std::wstring& textToPrint) {

	TEXTMETRIC tmetric;
	GetTextMetricsW(hdc, &tmetric);

	GetTextMetrics(hdc, &tmetric);

	// start doc pos
	int x = 100;
	int y = 100;
	int newLinePos = tmetric.tmHeight + LINE_OFFSET;

	for (const auto& ch : textToPrint)
		if (ch == L'\n')
			y += newLinePos;
		else
			TextOutW(hdc, x, y, &ch, 1);

}

void printDocument(const std::wstring& textToPrint) {

	// printer dialog
	PRINTDLG pdlg = { 0 };
	pdlg.lStructSize = sizeof(PRINTDLG);
	pdlg.Flags = PD_RETURNDC | PD_ALLPAGES;
	pdlg.hwndOwner = nullptr;

	if (PrintDlgW(&pdlg)) {
		DOCINFO dinfo = { 0 };

		dinfo.cbSize = sizeof(DOCINFO);
		dinfo.lpszDocName = SAMPLE_DOC_NAME;

		if (StartDocW(pdlg.hDC, &dinfo) > 0) {

			if (StartPage(pdlg.hDC) > 0) {

				printTextFile(pdlg.hDC, textToPrint);
				EndPage(pdlg.hDC);
			}
			EndDoc(pdlg.hDC);

		}
		DeleteDC(pdlg.hDC);
	}
}