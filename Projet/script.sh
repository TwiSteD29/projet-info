#!/bin/bash 
#script.sh

function menu_help () {

echo "*** Bienvenue dans le menu help ***"
echo "* Le nombre d'argument est peut être incorrect ou alors vous avez besoin d'aide."
echo "* Utilisation : ./$(basename $0) [-f <fichier>] (paramètre obligatoire)"
echo "* Paramètres supplémentaires : [-t arg] [-p arg] [-w] [-m] [-h] [-F] [-G] [-S] [-A] [-O] [-Q]"
echo "* Vous ne pouvez choisir qu'un seul territoire"
echo "* Voici les territoires disponibles : [-F](France) [-G](Guyane) [-S](SaintPierre) [-A](Antilles) [-O](Ocean) [-Q](Antarctique)"
echo "* Méthode de tri : [--tab] ou [--abr] ou [--avl] (une méthode de tri maximum)."
echo "* Méthode de tri par défaut : avl"
echo "* Voici le format pour saisir un intervalle pour la date (min puis max) : YYYY-MM-DD_YYYY-MM-DD "
echo "* le paramètres date est optionnel."
exit 1
}


function temp () {

		if [[ $modeT = 1 ]]
			then
			cut -d';' -f1,10,11,12,13 tmp > temp11
			echo "t1 ok"
			#chmod 755
			./tri_donnees temp11 $tri $territoire
			
		elif [[ $modeT = 2 ]]
			then
			cut -d';' -f1,2,10,11 tmp > temp2
			echo "t2 ok"
			./tri_donnees temp2 $tri $territoire
		elif [[ $modeT = 3 ]]
			then
			cut -d';' -f1,2,10,11 tmp > temp3
			echo "t3 ok"
			./tri_donnees temp3 $tri $territoire
		elif [[ $modeT -ne 1 ]] || [[ $modeT -ne 2 ]] || [[ $modeT -ne 3 ]]
			then
			echo "Le mode sélectionné pour la température n'existe pas. Veuillez choisir le mode 1, 2 ou 3 !"
		fi
}

function pres () {

		if [[ $modeP = 1 ]]
			then
			cut -d';' -f1,7,10 tmp > pres1
			echo "p1 ok"
			./tri_donnees pres1 $tri $territoire
		elif [[ $modeP = 2 ]]
			then
			cut -d';' -f1,2,7,10 tmp > pres2
			echo "p2 ok"
			./tri_donnees pres2 $tri $territoire
		elif [[ $modeP = 3 ]]
			then
			cut -d';' -f1,2,7,10 tmp > pres3
			echo "p3 ok"
			./tri_donnees pres3 $tri $territoire
		elif [[ $modeP != "1" ]] || [[ $modeP != "2" ]] || [[ $modeP != "3" ]]
			then
			echo "Le mode sélectionné pour la pression n'existe pas. Veuillez choisir le mode 1, 2 ou 3 !"
		fi
}

function vent () {

	cut -d';' -f1,4,5,10 tmp > vent 
	echo "w ok"
	./tri_donnees vent $tri $territoire
}

function humidite () {

	cut -d';' -f1,6,10 tmp > humidite
	echo "m ok"
	./tri_donnees humidite $tri $territoire
}

function altitude () {

	cut -d';' -f1,10,14 tmp > altitude 
	echo "h ok" 
	./tri_donnees altitude $tri $territoire   
}

function DATES () {
	
	DATE_min=`echo $DATES_intervalle | awk -F"_" '{print $1}'`
	DATE_max=`echo $DATES_intervalle | awk -F"_" '{print $2}' | awk -F" " '{print $1}'`
	echo "$DATE_min $DATE_max"
	
	./tri_donnees $DATE_min $DATE_max z1
}

function coords () {

	./tri_donnees $territoire z2
	exit
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
rm tmp1


while getopts ":t:p:f:-:d:wmhFGSAOQ" opt
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
	d) 	DATES_intervalle=$OPTARG
		option_DATES=1
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

if  [[ "$((restriction))" -gt 1 ]]  #On ne peut choisir qu'un seul territoire 
then 
	echo "Vous ne pouvez choisir qu'un seul territoire à la fois"
	menu_help
fi

parametres=0

let "parametres=parametres+option_temp+option_pres+option_vent+option_humidite+option_altitude"

if [[ "$((parametres))" -lt 1 ]] #On est obligé de choisir un paramètre.
then
	echo "Vous devez choisir au moins un type de données."
	menu_help
fi

tail -n+2 ${fichier} > tmp
sed 's/\(.*\)T[0-9]*:[0-9]*:[0-9]*+[0-9]*:[0-9]*;/\1;/' tmp > tmp1


if [[ ${option_DATES} = "1" ]]
then
	DATES
fi

if [[ ${option_france} = "1" ]]
then
	territoire=france5
	coords
fi

if [[ ${option_guyane} = "1" ]]
then
	territoire=guyane6
	coords
fi

if [[ ${option_saintpierre} = "1" ]]
then
	territoire=saintpierre7
	coords
fi

if [[ ${option_antilles} = "1" ]]
then
	territoire=antilles8
	coords
fi

if [[ ${option_ocean} = "1" ]]
then
	territoire=ocean9
	coords
fi

if [[ ${option_antarctique} = "1" ]]
then
	territoire=antarctique0
	coords
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


