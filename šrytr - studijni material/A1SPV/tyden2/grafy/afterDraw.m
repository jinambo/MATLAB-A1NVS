% Author: Karel Perutka

function afterDraw

%shading interp

light('Position',[0 0 0])
lightangle(320,-40)
set(gcf,'Renderer','OpenGL')
set(findobj(gca,'type','surface'),...
    'FaceLighting','phong',...
    'AmbientStrength',.3,'DiffuseStrength',.9,...
    'SpecularStrength',.1,'SpecularExponent',25,...
    'BackFaceLighting','reverselit','EdgeColor','none')
            
