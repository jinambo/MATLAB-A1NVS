function sifrovani

tlacitko=questdlg('Kterou operaci chcete prov�st?','�ifrov�n�','�ifrovat','De�ifrovat','Konec','Konec');
switch tlacitko,
    case '�ifrovat'
        %zadani jmena souboru pomoci dialogu
        [fileopen, pathopen] = uigetfile( ...
		{'*.txt','Textov� soubory (*.txt)'; 
            '*.*',  'V�echny soubory (*.*)'}, ...
            'Zvolte soubor pro za�ifrov�n�');

        %pokud byl zadan nazev souboru, program pokracuje v sifrovani
        if fileopen~=0
            %pridani predpony '_sif' k sifrovanemu souboru
            filesave=strcat('sif_',fileopen);
			
            %otevreni zdrojoveho souboru pro cteni a ciloveho pro zapis
            fin = fopen(fileopen,'r');
			fout = fopen(filesave,'w');
			
            %dokud neni konec souboru, opakuje se cyklus
            while ~feof(fin)
                %nacte znak ze zdrojoveho souboru
                A = fread(fin,1);
                %ulozi znak se zvysenou ASCII hodnotou do ciloveho souboru
                fwrite(fout,A+5);
			end
            
            %zavre soubory
			status = fclose(fin);
			status = fclose(fout);
            
            okmsg='�ifrov�n� souboru prob�hlo �sp�n�. Za�ifrovan� soubor byl ulo�en jako "';
            okmsg=strcat(okmsg,filesave);
            okmsg=strcat(okmsg,'".');
            %Zobrazeni hlaseni o stavu sifrovani
            questdlg(okmsg,'�ifrov�n�','OK','OK');
            
        else
            %pokud nebyl zadan nazev souboru, vypise se hlaseni
            questdlg('Nevybrali jste ��dn� soubor. Program bude ukon�en.','�ifrov�n�','OK','OK');
        end
            
    case 'De�ifrovat'
        %zadani jmena souboru pomoci dialogu
		[fileopen, pathopen] = uigetfile( ...
		{'*.txt','Textov� soubory (*.txt)'; 
            '*.*',  'V�echny soubory (*.*)'}, ...
            'Zvolte soubor pro de�ifrov�n�');
		
        %pokud byl zadan nazev souboru, program pokracuje v sifrovani
        if fileopen~=0
            %odstrani predponu 'sif_' ze zdrojoveho nazvu souboru
            filesave=regexprep(fileopen,'sif_','');
            
            %otevreni zdrojoveho souboru pro cteni a ciloveho pro zapis
			fin = fopen(fileopen,'r');
			fout = fopen(filesave,'w');
			
            %dokud neni konec souboru, opakuje se cyklus
			while ~feof(fin)
                %nacte znak ze zdrojoveho souboru
                A = fread(fin,1);
                %ulozi znak se snizenou ASCII hodnotou do ciloveho souboru
                fwrite(fout,A-5);
			end
			
            %zavre soubory
			status = fclose(fin);
			status = fclose(fout);
	
            okmsg='De�ifrov�n� souboru prob�hlo �sp�n�. De�ifrovan� soubor byl ulo�en jako "';
            okmsg=strcat(okmsg,filesave);
            okmsg=strcat(okmsg,'".');
            %Zobrazeni hlaseni o stavu sifrovani
            questdlg(okmsg,'�ifrov�n�','OK','OK');
    
        else
            %pokud nebyl zadan nazev souboru, vypise se hlaseni
            questdlg('Nevybrali jste ��dn� soubor. Program bude ukon�en.','�ifrov�n�','OK','OK');
        end
end
