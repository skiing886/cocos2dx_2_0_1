require "extern"

MySprite = class("MySprite",
			function(szFileName)
				return CCSprite:create(szFileName);
			end
);
MySprite.__index = MySprite;
MySprite.type = 0;

function MySprite:createMS(szFileName, _type)
	local mySprite = MySprite.new(szFileName);	
	mySprite:myInit(_type);
	return mySprite;		
end
function MySprite:myInit(_type)
	self.type = _type;
end