using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyScript : ObjScript
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
        return Manager.GetComponent<CreateBoard>().getFriendly();
    }

    protected override string GetEnemyStr()
    {
        return "Friendly";
    }

    protected override bool GetEnemy(GameObject enemy)
    {
        return enemy.GetComponent<BoardScript>().getisOnFriendly();
    }

    protected override void Spell()
    {

    }
}
