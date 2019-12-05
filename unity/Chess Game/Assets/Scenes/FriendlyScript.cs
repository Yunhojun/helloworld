using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FriendlyScript : ObjScript
{
    // Start is called before the first frame update
    void Start()
    {
        
    }
    
    // Update is called once per frame
    void Update()
    {
        
    }

    protected override Vector2[] GetEnemy()
    {
        return Manager.GetComponent<CreateBoard>().getEnemy();
    }

    protected override string GetEnemyStr()
    {
        return "Enemy";
    }

    protected override bool GetEnemy(GameObject enemy)
    {
        return enemy.GetComponent<BoardScript>().getisOnEnemy();
    }

    protected override void Spell()
    {

    }
}
