import os
from PyPDF2 import PdfFileMerger, PdfFileReader

root = os.getcwd()
lista=[]
for path, subdirs, files in os.walk(root):
    for name in files:
        lista.append(name)

for add in lista:
    if(add!="imprimir.py"):
        cmd = "code2pdf -l "+add
        os.system(cmd)

pdfs=[]
for file in os.listdir(root):
    if file.endswith(".pdf"):
        pdfs.append(file)

merger = PdfFileMerger()

for pdf in pdfs:
    merger.append(open(pdf, 'rb'))

with open("cadernaveis.pdf", "wb") as fout:
    merger.write(fout)

for file in os.listdir(root):
    if file.endswith(".pdf"):
        if(file!="cadernaveis.pdf"):
            os.system("rm "+file)