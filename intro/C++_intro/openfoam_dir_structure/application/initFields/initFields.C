/*
Unsteady heat conduction equation solver; also the simplest skeleton of an
openfoam solver.

Written by Maalik, alishayegh@tensorfields.com
02-04-2024, Green Office, TensorFields, Dublin.
*/

#include "Time.H"
#include "IOdictionary.H"
#include "IOobject.H"
#include "argList.H"
#include "fvMesh.H"
#include "fvScalarMatrix.H"
#include "fvm.H"
#include "geometricZeroField.H"
#include "fvModels.H"
#include "fvConstraints.H"

using namespace Foam;
int main(int argc, char* argv[])
{
    argList args(argc, argv);
	Time runTime("controlDict", args);
    IOdictionary dict
	(
	    IOobject
		(
			"transportProperties",
		    runTime.constant(),
			runTime,
			IOobject::MUST_READ,
			IOobject::NO_WRITE
		)

	);

    fvMesh mesh
    (
        IOobject
        (
            fvMesh::defaultRegion,
            runTime.timeName(),
            runTime,
            IOobject::MUST_READ
        )
    );

    volScalarField p
    (
        IOobject
        (
            "p",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

	dimensionedScalar k 
	(
		"k",
		pow(dimLength,2)/dimTime,
		dict.lookup("k")
	);

    while (runTime.loop())
	{
	    fvScalarMatrix pEqn
		(
		    fvm::ddt(p) - 
			fvm::laplacian(k, p) == geometricZeroField()
		);
        pEqn.solve();

	   runTime.write();
	}
}
