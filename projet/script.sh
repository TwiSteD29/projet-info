#!/bin/bash 
#script.sh

function menu_help () {

echo "*** Bienvenue dans le menu help ***"
echo "* Le nombre d'argument est peut être incorrect ou alors vous avez besoin d'aide."
echo "* Utilisation : ./$(basename $0) [-f <fichier>] (paramètre obligatoire)"
echo "* Paramètres supplémentaires : [-t arg] [-p arg] [-w] [-m] [-h] [-F] [-G] [-S] [-A] [-O] [-Q]"
echo "* Vous devez choisir au moins un territoire. (max = 1 territoire)"
echo "* Voici les territoires disponibles : [-F](France) [-G](Guyane) [-S](SaintPierre) [-A](Antilles) [-O](Ocean) [-Q](Antarctique)"
echo "* Méthode de tri : [--tab] ou [--abr] ou [--avl] (une méthode de tri maximum)."
echo "* Méthode de tri par défaut : avl"
exit 1
}


function temp () {

		if [[ $modeT = 1 ]]
			then
			cut -d';' -f1,11 tmp2 > temp1
			echo "t1 ok"
			#chmod 777
			#./tri_donnees temp1 $tri
			
		elif [[ $modeT = 2 ]]
			then
			cut -d';' -f1,2,11 tmp2 > temp2
			echo "t2 ok"
		elif [[ $modeT = 3 ]]
			then
			cut -d';' -f1,2,11 tmp2 > temp3
			echo "t3 ok"
		elif [[ $modeT -ne 1 ]] || [[ $modeT -ne 2 ]] || [[ $modeT -ne 3 ]]
			then
			echo "Le mode sélectionné pour la température n'existe pas. Veuillez choisir le mode 1, 2 ou 3 !"
		fi
}

function pres () {

		if [[ $modeP = 1 ]]
			then
			cut -d';' -f1,7 tmp2 > pres1
			echo "p1 ok"
		elif [[ $modeP = 2 ]]
			then
			cut -d';' -f1,2,7 tmp2 > pres2
			echo "p2 ok"
		elif [[ $modeP = 3 ]]
			then
			cut -d';' -f1,2,7 tmp2 > pres3
			echo "p3 ok"
		elif [[ $modeP != "1" ]] || [[ $modeP != "2" ]] || [[ $modeP != "3" ]]
			then
			echo "Le mode sélectionné pour la pression n'existe pas. Veuillez choisir le mode 1, 2 ou 3 !"
		fi
}

function vent () {

	cut -d';' -f1,4,5 tmp2 > vent 
	echo "w ok"
}

function humidite () {

	cut -d';' -f1,6 tmp2 > humidite
	echo "m ok"
}

function altitude () {

	cut -d';' -f1,14 tmp2 > altitude4 #cest normal
	echo "h ok"    
}

function antilles_zone2 () {

	Xmax=21.05
	Xmin=11.60
	Ymin=-75.32
    	Ymax=-58.31

	for i in `head -10 tmp`
	do 
                ligne=`echo $i`
                X=`echo $ligne |awk -F";" '{print $10}' | awk -F"," '{print $1}'`
		Y=`echo $ligne |awk -F";" '{print $10}' | awk -F"," '{print $2}'` 
		#echo " $X , $Y "

		if [[ $(echo "$X < $Xmax"|bc) -eq 1 ]] && [[ $(echo "$X > $Xmin"|bc) -eq 1 ]] && [[ $(echo "$Y < $Ymax"|bc) -eq 1 ]] && [[ $(echo "$Y > $Ymin"|bc) -eq 1 ]]
		then
			#echo " $X , $Y "
                        
			echo "$ligne" >> tmp2	
		fi
	done	

}

function coord () {
   case $1 in 
   	france)
		Xmax=52 
		Xmin=41 
		Ymin=-6
    		Ymax=10
        ;;
        antilles)
		Xmax=-2.55
		Xmin=-26.82
		Ymin=41.44
    		Ymax=63.44
        ;;   
	guyane)
		Xmax=9.28
		Xmin=-0.23
		Ymin=-62.70
    		Ymax=-50.30
	;;
	saintpierre)
		Xmax=47.17
		Xmin=46.70
		Ymin=-56.50 
    		Ymax=-56
	;;
	ocean)
		Xmax=-28.26
		Xmin=-61.59
		Ymin=26.10
    		Ymax=106.48
	;;
	antarctique)
		Xmax=-62.70
		Xmin=-82.80
		Ymin=73.20
    		Ymax=163
esac     
	echo "$Xmin $Xmax $Ymin $Ymax"

        rm tmp2
	tail -n+2 ${fichier} > tmp
	for i in `head -10 tmp`
	do 
                ligne=`echo $i`
                X=`echo $ligne |awk -F";" '{print $10}' | awk -F"," '{print $1}'`
		Y=`echo $ligne |awk -F";" '{print $10}' | awk -F"," '{print $2}'` 
		#echo " $X , $Y "

		if [[ $(echo "$X < $Xmax"|bc) -eq 1 ]] && [[ $(echo "$X > $Xmin"|bc) -eq 1 ]] && [[ $(echo "$Y < $Ymax"|bc) -eq 1 ]] && [[ $(echo "$Y > $Ymin"|bc) -eq 1 ]]
		then
			#echo " $X , $Y "
                        
			echo "$ligne" >> tmp2	
		fi
	done	
}


if [[ $# -lt 2 ]]
then
	menu_help
fi

fichier=`echo $@ | awk -F "-f" '{print $2}'|awk -F" " '{print $1}'` #on récupère l'argument après -f
echo "$fichier"
if [[ -z $fichier ]] #si pas d'argument après -f alors menu help
then
menu_help
fi

if [[ ! -f $fichier ]]
then 
	echo "L'argument n'est pas un fichier."
	echo "Faites --help si vous avez besoin d'aide."
	exit 2
fi


echo "Bienvenue sur la météo"

while getopts ":t:p:f:-:wmhFGSAOQ" opt
do
if [[ $opt = "-" ]]
then
 opt=$OPTARG
fi
case $opt in

	help)	menu_help
	;;
	
	tab)	option_tab=1
		tri=$OPTARG	
	;;
	
	abr)	option_abr=1
		tri=$OPTARG
	;;

	avl)	option_avl=1
		tri=$OPTARG
	;;

	f) 	fichier=$OPTARG
		
	;;	
	t) 	modeT=$OPTARG
		option_temp=1
	;;
	p) 	modeP=$OPTARG
		option_pres=1
	;;
	w) 	option_vent=1
	;;
	m)	option_humidite=1
	;;
	h) 	option_altitude=1
	;;
	F)	option_france=1
		
	;;
	G)	option_guyane=1
			
	;;
	S)	option_saintpierre=1
		
	;;
	A)	option_antilles=1
		
	;;
	O)	option_ocean=1
		
	;;
	Q)	option_antarctique=1

	;;
	*) 	echo "TEST"
		menu_help
		exit 3
esac
done


if [[ -z $tri ]] #si pas de mode de tri choisit par l'utilisateur alors "avl" par défaut
then
 tri=avl
fi

rest_tri=0

let "rest_tri=rest_tri+option_tab+option_avl+option_abr"

if [[ "$((rest_tri))" -gt 1 ]]	#On ne peut choisir qu'un seul mode de tri 
then
	echo "Vous avez choisi plus d'une méthode tri."
	menu_help
fi

restriction=0

let "restriction=restriction+option_france+option_guyane+option_antilles+option_saintpierre+option_ocean+option_antarctique"

if  [[ "$((restriction))" -ne 1 ]]  #On ne peut choisir qu'un seul territoire et on est obligé d'en choisir un
then 
	echo "Problèmes de territoire"
	menu_help
fi

if [[ ${option_france} = "1" ]]
then
	coord france
fi

if [[ ${option_guyane} = "1" ]]
then
	coord guyane
fi

if [[ ${option_saintpierre} = "1" ]]
then
	coord saintpierre
fi

if [[ ${option_antilles} = "1" ]]
then
	coord antilles
	antilles_zone2
fi

if [[ ${option_ocean} = "1" ]]
then
	coord ocean
fi

if [[ ${option_antarctique} = "1" ]]
then
	coord antarctique
fi

if [[ ${option_temp} = "1" ]]
then
	temp
fi

if [[ ${option_pres} = "1" ]]
then
	pres
fi

if [[ ${option_vent} = "1" ]]
then
	vent
fi

if [[ ${option_humidite} = "1" ]]
then
	humidite
fi

if [[ ${option_altitude} = "1" ]]
then
	altitude
fi


