classdef signature
    %
    %   Class:
    %   git.base.signature
    
    properties
        full_name
        email
        when
    end
    
    methods
        function obj = signature(s)
            %
            %   obj = git.base.signature(s)
            obj.full_name = s.name;
            obj.email = s.email;
            
            %TODO: Convert to datenum
            obj.when = s.when;
        end
    end
    
end

%git_signature_default
%git_signature_dup
%git_signature_free
%git_signature_from_buffer
%git_signature_new
%git_signature_now