
/* Copyright (c) 2013 thayumk@gmail.com. All rights reserved. */
var camera, scene, renderer;
var container;
var cube;


function init()
{
  var cHeight= window.innerHeight;
  var cWidth= window.innerWidth;
 
  // RENDERER
  renderer= new THREE.WebGLRenderer();
  renderer.setSize(cWidth, cHeight);
  renderer.setClearColor( 0x000000, 1.0 );
  // CAMERA
  var aspectRatio= cWidth/cHeight;
  camera= new THREE.PerspectiveCamera(70,aspectRatio, 0.1, 1000);
  //camera.position.set(-10, 20, 20);
  camera.position.z=500;
  //camera.position.y=0;
}


function fillScene()
{
  scene= new THREE.Scene();
  camera.lookAt(scene.position);
    
  // Add cube to scene
  var cubeGeometry= new THREE.CubeGeometry(45, 45, 45);
  var cubeMaterial= new THREE.MeshNormalMaterial();
  var cubeGroup= new THREE.Object3D();

  for (var i=0;i<150;i++)
  {
    var cube= new THREE.Mesh(cubeGeometry, cubeMaterial);
    cube.position.x=Math.random()*700-250;
    cube.position.y=Math.random()*700-250;
    cube.position.z=Math.random()*1000-400;
    cube.rotation.z=Math.random()*270*180/Math.PI;
    cubeGroup.add(cube);
  }

  scene.add(cubeGroup);

  var light = new THREE.PointLight( 0xFFFF00 );
  light.position.set( 10, 0, 10 );
  scene.add( light );
}


function addToDOM()
{
  document.body.appendChild( renderer.domElement );	
}


function render()
{
  if ( camera.position.z < 250)
    camera.position.z=700;
    
  camera.position.z-= 3;
  camera.lookAt(scene.position);
  renderer.render(scene, camera);
}

function animate()
{
  render();
  window.requestAnimationFrame(animate);	
}


try
{
  init();
  addToDOM();
  fillScene();
  addToDOM();
  animate(new Date().getTime());
} catch(e)
{
  document.writeln("caught error"+e);
}
