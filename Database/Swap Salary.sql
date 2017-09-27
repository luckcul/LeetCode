update salary set sex = if(sex='m', 'f', 'm');

update salary set sex = char(ASCII(sex) ^ ASCII('m') ^ ASCII('f'));