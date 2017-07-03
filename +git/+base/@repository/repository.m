classdef repository
    %
    %   Class:
    %   git.base.repository
    
    %{
        file_path = '/Users/jim/Documents/repos/matlab_git/matlab_standard_library'
        repo = git.base.repository(file_path)
    %}
    
    properties (Hidden)
        h %pointer for underlying git_repository 
    end
    
    properties
        file_path
    end
    
    %Repo creation methods
    methods (Static)
        
    end
    
    methods
        function obj = repository(file_path)
            %
            %   obj = git.base.repository(file_path)
            
            obj.file_path = file_path;
            obj.h = libgit(0,26,file_path);
        end
        function getNamespace(obj)
            %TODO
        end
        function delete(obj)
            libgit(0,7,obj.h);
        end
    end
    
end

