
use File::Path qw(remove_tree rmtree);


$WorkDic = [ 'kernel/ISO_Context',
             'kernel/ISO_Lib',
             'kernel/ISO_Pass',
             'kernel/ISO_Parser',
             'kernel/SC_Context',
             'kernel/SC_Lib',
             'kernel/SC_Parser' ];

$glDir = `pwd`;
chomp $glDir;

$glBuild = $glDir.'/Build';


 
sub gen_ISO_Parser {

my $iISO_yacc = $glDir.'/kernel/ISO_Parser/ISO_Parser.y';           
my $iISO_lex  = $glDir.'/kernel/ISO_Parser/ISO_Tokens.l';

my $oISO_yacc = $glDir.'/kernel/ISO_Parser/ISO_Parser.cpp';
my $oISO_lex  = $glDir.'/kernel/ISO_Parser/ISO_Tokens.cpp';

if(!-e $iISO_yacc &&
   !-e $iISO_lex  ){ die "ISO_Parser Error"; }

system("bison -d -p ISO_ -o $oISO_yacc   $iISO_yacc");
system("lex -o              $oISO_lex    $iISO_lex ");

}



sub gen_SC_Parser { 

my $iSC_yacc = $glDir.'/kernel/SC_Parser/SC_Parser.y';           
my $iSC_lex  = $glDir.'/kernel/SC_Parser/SC_Tokens.l';

my $oSC_yacc = $glDir.'/kernel/SC_Parser/SC_Parser.cpp';
my $oSC_lex  = $glDir.'/kernel/SC_Parser/SC_Tokens.cpp';

if(!-e $iSC_yacc &&
   !-e $iSC_lex  ){ die "SC_Parser Error"; }

system("bison -d -p SC_ -o $oSC_yacc  $iSC_yacc");
system("lex -o             $oSC_lex   $iSC_lex");

}



sub gen_Object_code {

if(-e $glBuild){
   system(rm -r $glBuild);
}
 
   system(mkdir $glBuild);

   foreach my $ww ( @{$WorkDic} ){
           my $ww = $glDir.'/'.$ww;     

           chdir $ww;   
           my @cpps = `ls | grep cpp`;
          
           foreach my $cpp ( @cpps ){
                   chomp $cpp;
                   my $obj = $cpp;
                      $obj =~ s/\.cpp/\.o/g;

                   my $comd = 'g++ -O3 -c '.$cpp.' -I '.$glDir.' -o '.$glBuild.'/'.$obj;
                     `$comd`;
           }
   }


  chdir $glDir.'/kernel';
  my $comd = 'g++ -O3 -c '.$glDir.'/kernel/main.cpp -I '.$glDir.' -o'.$glBuild.'/main.o';
    `$comd`;
}



sub gen_Link_code {

    chdir $glBuild;
    my $comd = `g++ *.o -o ISO_Pass.out`;
       `$comd`;
    `mv ISO_Pass.out ..`;     
}



sub run_test_Big1 {

chdir $glDir;

 my $comd = './ISO_Pass.out -design         test/Big1.v   \
                            -library        test/Big1.l   \
                            -root           Big1          \
                            -power_intent   test/Big1.pi  \
                            -report         Big1.log';  
    exec $comd;
}



sub run_test_Big3 {

chdir $glDir;

 my $comd = './ISO_Pass.out  -design         test/Big3.v   \
                             -library        test/Big3.l   \
                             -root           Big3          \
                             -power_intent   test/Big3.pi  \
                             -report         Big3.log';    
    exec $comd;
}


gen_ISO_Parser();
gen_SC_Parser();
gen_Object_code();
gen_Link_code();
run_test_Big1();
#run_test_Big3();                
