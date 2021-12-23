#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

/*
<<<<<<< HEAD
 *	Traduit un fichier de type d�finition de labyrinthe au format interne.
=======
 *	Traduit un fichier de type d�finition de labyrinthe au format interne.
>>>>>>> 96cfe169e7c456d1131c3ac5a2a96bff193c57d2
 */

#define EMPTY	0		// case vide (ou on peut marcher!)

<<<<<<< HEAD
// affiche un message en haut � gauche de l'�cran.
extern void message (const char* format, ...);

// affiche en gros si on a gagn� ou perdu la partie et invalide les tirs.
=======
// affiche un message en haut � gauche de l'�cran.
extern void message (const char* format, ...);

// affiche en gros si on a gagn� ou perdu la partie et invalide les tirs.
>>>>>>> 96cfe169e7c456d1131c3ac5a2a96bff193c57d2
extern void partie_terminee (bool winned);

class Mover;

struct Wall {
	int	_x1, _y1;	// point de depart.
<<<<<<< HEAD
	int	_x2, _y2;	// point d'arriv�e.
	int	_ntex;		// num�ro de texture.
=======
	int	_x2, _y2;	// point d'arriv�e.
	int	_ntex;		// num�ro de texture.
>>>>>>> 96cfe169e7c456d1131c3ac5a2a96bff193c57d2
};

struct Box {
	int	_x, _y;		// emplacement.
<<<<<<< HEAD
	int	_ntex;		// num�ro de texture.
=======
	int	_ntex;		// num�ro de texture.
>>>>>>> 96cfe169e7c456d1131c3ac5a2a96bff193c57d2
};

class Environnement {
public:
	static const int scale;		// facteur d'echelle (defini par moi, mais utilise par vous)
<<<<<<< HEAD
	static const char* texture_dir;	// r�pertoire des textures.
	static const char* modele_dir;	// r�pertoire des personnages.
/*
 * la fonction de cr�ation du labyrinthe � d�finir DANS Labyrinthe.cpp de la fa�on suivante:
=======
	static const char* texture_dir;	// r�pertoire des textures.
	static const char* modele_dir;	// r�pertoire des personnages.
/*
 * la fonction de cr�ation du labyrinthe � d�finir DANS Labyrinthe.cpp de la fa�on suivante:
>>>>>>> 96cfe169e7c456d1131c3ac5a2a96bff193c57d2
 * 
 * Environnement* Environnement::init (char* filename) {
 *	return new Labyrinthe (filename);
 * }
 * 
 * 
 */
	static Environnement* init (char* filename);

	Wall*	_walls;		// les murs sous forme de tableau de segments.
	int		_nwall;		// le nombre de segments.
	Wall*	_picts;		// les affiches.
	int		_npicts;	// leur nombre.
	Box*	_boxes;		// les caisses.
	int		_nboxes;	// leur nombre.

/* DEB - NOUVEAU */
	Box*	_marks;		// les marques au sol.
	int		_nmarks;	// leur nombre.
/* FIN - NOUVEAU */

<<<<<<< HEAD
	Box		_treasor;	// le tr�sor.
=======
	Box		_treasor;	// le tr�sor.
>>>>>>> 96cfe169e7c456d1131c3ac5a2a96bff193c57d2
	Mover**	_guards;	// les gardes (tableau de pointeurs de gardiens).
	int		_nguards;	// leur nombre.

	virtual int width () =0;	// retourne la largeur du labyrinthe.
	virtual int height () =0;	// retourne la longueur du labyrinthe.
	virtual char data (int i, int j) =0;	// retourne la case (i, j).
	virtual ~Environnement () {}
	// reconsidere le labyrinthe pour le reafficher.
	// fonction a n'appeller QUE si les murs ou les caisses ou le tresor BOUGENT
	void reconfigure ();
<<<<<<< HEAD
	// retourne le numero de texture pour le fichier image pass� en argument.
	int wall_texture (char*);
	// recr�e les boules de feu des movers.
	// fonction a n'appeller QUE si des gardiens sont recr��s.
=======
	// retourne le numero de texture pour le fichier image pass� en argument.
	int wall_texture (char*);
	// recr�e les boules de feu des movers.
	// fonction a n'appeller QUE si des gardiens sont recr��s.
>>>>>>> 96cfe169e7c456d1131c3ac5a2a96bff193c57d2
	void make_fireballs (void);
};

#endif
