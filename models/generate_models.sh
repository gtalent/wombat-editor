cat enginemodels.cy > models.cy
cat editormodels.cy >> models.cy
cyborgbear -i models.cy -o models -n models -t cpp-qt -lc
rm -f models.cy
liccor > /dev/null
