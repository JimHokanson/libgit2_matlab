classdef userpass
    %
    %   Class:
    %   git.base.cred.userpass
    
    properties
        user_name
        password
    end
    
    methods
        function obj = userpass(user_name,password)
            obj.user_name = user_name;
            obj.password = password;
        end
    end
    
end

