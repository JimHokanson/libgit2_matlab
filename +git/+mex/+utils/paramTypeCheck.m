function paramTypeCheck(varargin)

    %git.mex.util.paramTypeCheck(varargin)
    %
    %git.mex.util.paramTypeCheck(var1,type1,var2,type2)
    
    error2 = @(x,y)error('Incorrect input type, expected: "%s", observed: "%s"',x,class(y));
    
    for i = 1:2:length(varargin)
        var = varargin{i};
        type = varargin{i+1};
        switch type
            case 'pointer'
                if ~isa(var,'int64')
                    error2('pointer/int64',var)
                end
            case 'char'
                if ~isa(var,'char')
                    error2('char',var)
                end
            otherwise
                error('Type not yet implemented: %s',class(type))
        end
    end

end
