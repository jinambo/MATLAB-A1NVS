function sifrovani

tlacitko=questdlg('Kterou operaci chcete provést?','Šifrování','Šifrovat','Dešifrovat','Konec','Konec');
switch tlacitko,
    case 'Šifrovat'
        %zadani jmena souboru pomoci dialogu
        [fileopen, pathopen] = uigetfile( ...
		{'*.txt','Textové soubory (*.txt)'; 
            '*.*',  'Všechny soubory (*.*)'}, ...
            'Zvolte soubor pro zašifrování');

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
            
            okmsg='Šifrování souboru probìhlo úspìšnì. Zašifrovaný soubor byl uložen jako "';
            okmsg=strcat(okmsg,filesave);
            okmsg=strcat(okmsg,'".');
            %Zobrazeni hlaseni o stavu sifrovani
            questdlg(okmsg,'Šifrování','OK','OK');
            
        else
            %pokud nebyl zadan nazev souboru, vypise se hlaseni
            questdlg('Nevybrali jste žádný soubor. Program bude ukonèen.','Šifrování','OK','OK');
        end
            
    case 'Dešifrovat'
        %zadani jmena souboru pomoci dialogu
		[fileopen, pathopen] = uigetfile( ...
		{'*.txt','Textové soubory (*.txt)'; 
            '*.*',  'Všechny soubory (*.*)'}, ...
            'Zvolte soubor pro dešifrování');
		
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
	
            okmsg='Dešifrování souboru probìhlo úspìšnì. Dešifrovaný soubor byl uložen jako "';
            okmsg=strcat(okmsg,filesave);
            okmsg=strcat(okmsg,'".');
            %Zobrazeni hlaseni o stavu sifrovani
            questdlg(okmsg,'Šifrování','OK','OK');
    
        else
            %pokud nebyl zadan nazev souboru, vypise se hlaseni
            questdlg('Nevybrali jste žádný soubor. Program bude ukonèen.','Šifrování','OK','OK');
        end
end
